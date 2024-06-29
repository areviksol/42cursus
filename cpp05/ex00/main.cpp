#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	obj("Tom", 150);
		std::cout << obj;
		for (int i = 0; i < 5; i++)
			obj.decrement();
		std::cout << obj;
		for (int i = 0; i < 5; i++)
			obj.increment();
		std::cout << obj;
	}
	catch(const std::exception &e)
		{std::cout << e.what() << std::endl;}
	return (0);
}