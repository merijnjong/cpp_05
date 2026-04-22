#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void section(const std::string &name)
{
	std::cout << "\n--- " << name << " ---" << std::endl;
}

int main(void)
{
	section("TEST 1: sign + execute shrubbery (should succeed)");
	try
	{
		Bureaucrat admin("Admin", 1, 1);
		ShrubberyCreationForm formA("targetA");
		admin.signForm(formA);
		admin.executeForm(formA);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	section("TEST 2: execute unsigned form (should fail)");
	try
	{
		Bureaucrat userA("UserA", 10, 10);
		RobotomyRequestForm formB("targetB");
		userA.executeForm(formB);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	section("TEST 3: signed form executed by low executor (should fail)");
	try
	{
		Bureaucrat signer("Signer", 1, 1);
		Bureaucrat userB("UserB", 1, 120);
		PresidentialPardonForm formC("targetC");
		signer.signForm(formC);
		userB.executeForm(formC);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected failure: " << e.what() << std::endl;
	}

	section("TEST 4: robotomy twice (shows random success/failure)");
	try
	{
		Bureaucrat admin2("Admin2", 1, 1);
		RobotomyRequestForm formD("targetD");
		admin2.signForm(formD);
		admin2.executeForm(formD);
		admin2.executeForm(formD);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
