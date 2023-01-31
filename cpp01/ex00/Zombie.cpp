
#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::getname()
{
	return (_name);
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << srd::endl;
}

Zombie::~Zombie()
{

}
