#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "== Successful execution path ==" << std::endl;
	try
	{
		Bureaucrat chief("Chief", 1, 1);
		ShrubberyCreationForm garden("office_garden");
		chief.signForm(garden);
		chief.executeForm(garden);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Execute blocked when form is unsigned ==" << std::endl;
	try
	{
		Bureaucrat operatorA("OperatorA", 10, 10);
		RobotomyRequestForm target("Unit42");
		operatorA.executeForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Execute blocked when executor grade is too low ==" << std::endl;
	try
	{
		Bureaucrat signer("Signer", 1, 120);
		PresidentialPardonForm pardon("Arthur");
		signer.signForm(pardon);
		signer.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Robotomy randomness demo ==" << std::endl;
	try
	{
		Bureaucrat engineer("Engineer", 1, 1);
		RobotomyRequestForm robotomy("Bender");
		engineer.signForm(robotomy);
		engineer.executeForm(robotomy);
		engineer.executeForm(robotomy);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
