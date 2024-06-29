#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form deal("WRITE ",  true,  123, 1);

		std::cout << deal << std::endl;

		deal.beSigned(Bureaucrat("Sama", 1));

		std::cout << deal << std::endl;
		
		deal.beSigned(Bureaucrat("Sama", 124));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception >>>>>: " << e.what() << std::endl;
	}
}