#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern intern;
	Bureaucrat ceo("CEO", 1, 1);
	Bureaucrat operatorLow("OperatorLow", 1, 140);

	std::cout << "== Intern creates and CEO executes every valid form ==" << std::endl;
	const std::string names[3] = {
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};
	const std::string targets[3] = {
		"Trillian",
		"hq_garden",
		"Marvin"
	};
	for (int i = 0; i < 3; ++i)
	{
		AForm *form = NULL;
		try
		{
			form = intern.makeForm(names[i], targets[i]);
			std::cout << *form << std::endl;
			ceo.signForm(*form);
			ceo.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form;
	}

	std::cout << "\n== Unknown form name handled ==" << std::endl;
	try
	{
		AForm *unknown = intern.makeForm("weekly report", "nobody");
		delete unknown;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n== Signed but execution rejected because executor is too low ==" << std::endl;
	AForm *hardForm = NULL;
	try
	{
		hardForm = intern.makeForm("presidential pardon", "Ford");
		operatorLow.signForm(*hardForm);
		operatorLow.executeForm(*hardForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete hardForm;

	return (0);
}
