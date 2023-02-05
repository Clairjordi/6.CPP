/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:14:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 10:23:46 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp()
{
	char buffer[128];
	std::time_t result;
	
	result = std::time(NULL);
	std::tm *now = std::localtime(&result);
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
	std::cout << "[" << buffer << "] ";

}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout <<"accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

Account::Account(int initial_deposit) 
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount<< ";";
	std::cout << "created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposits:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	if (deposit > 0)
		_nbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += _nbDeposits;

}

int Account::checkAmount() const
{
	if (_amount < 0)
		return (1);
	return (0);
}

bool Account::makeWithdrawal(int withdrawal)
{
	int tmp;

	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	tmp = _amount;
	_amount -= withdrawal;
	if (checkAmount() == 1)
	{
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		_amount = tmp;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += _nbWithdrawals;
		return (true);
	}
}

Account::~Account()
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;

}
