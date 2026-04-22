#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void section(const std::string &title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	Intern intern;
	Bureaucrat admin("Admin", 1, 1);
	Bureaucrat userLowExec("UserLowExec", 1, 140);
	AForm *form = NULL;

	section("TEST 1: create/sign/execute presidential pardon (should succeed)");
	try
	{
		form = intern.makeForm("presidential pardon", "targetA");
		admin.signForm(*form);
		admin.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	form = NULL;

	section("TEST 2: create/sign/execute shrubbery (should succeed)");
	try
	{
		form = intern.makeForm("shrubbery creation", "targetB");
		admin.signForm(*form);
		admin.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	form = NULL;

	section("TEST 3: create/sign/execute robotomy (should succeed)");
	try
	{
		form = intern.makeForm("robotomy request", "targetC");
		admin.signForm(*form);
		admin.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete form;
	form = NULL;

	section("TEST 4: unknown form name (should fail)");
	try
	{
		form = intern.makeForm("unknown form", "targetX");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}
	delete form;
	form = NULL;

	section("TEST 5: low executor executes signed form (should fail)");
	try
	{
		form = intern.makeForm("presidential pardon", "targetD");
		userLowExec.signForm(*form);
		userLowExec.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected error: " << e.what() << std::endl;
	}
	delete form;

	return (0);
}
