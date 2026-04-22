#include "Bureaucrat.hpp"

int main()
{
	std::cout << "== Valid promotion / demotion ==" << std::endl;
	try
	{
		Bureaucrat analyst("Analyst", 3);
		std::cout << analyst << std::endl;
		analyst.incrementGrade();
		std::cout << "After promotion: " << analyst << std::endl;
		analyst.decrementGrade();
		std::cout << "After demotion: " << analyst << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected failure: " << e.what() << std::endl;
	}

	std::cout << "\n== Constructor bounds ==" << std::endl;
	try
	{
		Bureaucrat impossibleHigh("ImpossibleHigh", 0);
		std::cout << impossibleHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught high-bound exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat impossibleLow("ImpossibleLow", 151);
		std::cout << impossibleLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught low-bound exception: " << e.what() << std::endl;
	}

	std::cout << "\n== Runtime bounds ==" << std::endl;
	try
	{
		Bureaucrat director("Director", 1);
		director.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Increment blocked at top rank: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat trainee("Trainee", 150);
		trainee.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Decrement blocked at lowest rank: " << e.what() << std::endl;
	}
	return (0);
}