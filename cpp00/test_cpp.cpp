#include <ctime>
#include <iostream>
 
int main()
{
    std::time_t result = std::time(NULL);
	std::tm *now = std::localtime(&result);

	char buffer[128];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);

	std::cout << buffer;
}
