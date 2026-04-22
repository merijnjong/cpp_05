#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "== Signing works with enough rank ==" << std::endl;
	try
	{
		Form accessRequest("AccessRequest", 30);
		Bureaucrat manager("Manager", 10);
		std::cout << accessRequest << std::endl;
		manager.signForm(accessRequest);
		std::cout << accessRequest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Same form signed twice ==" << std::endl;
	try
	{
		Form budgetUpdate("BudgetUpdate", 60);
		Bureaucrat lead("Lead", 20);
		lead.signForm(budgetUpdate);
		lead.signForm(budgetUpdate);
		std::cout << budgetUpdate << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Sign rejected when rank too low ==" << std::endl;
	try
	{
		Form confidential("Confidential", 3);
		Bureaucrat assistant("Assistant", 100);
		assistant.signForm(confidential);
		std::cout << confidential << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Invalid form creation ==" << std::endl;
	try
	{
		Form invalid("InvalidForm", 0);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
