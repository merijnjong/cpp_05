/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 12:02:20 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	AForm	*form;
	Intern	Newbie;
	std::cout << PINK "\n--Making a Bureaucrat called Bob who is going to sign the forms--" RESET << std::endl;
	Bureaucrat	Bob("Bob", 1, 1);
	form = NULL;
	std::cout << PINK "\n--Create all types of forms and a form with incorrect type--" RESET << std::endl;
	
	{
		try
		{
			std::cout << BLUE "\n--Creating PresidentialPardonForm--" RESET << std::endl;
			form = Newbie.makeForm("presidential pardon", "Adam");
			std::cout << *form << std::endl;
			Bob.signForm(*form);
			std::cout << *form << std::endl;
			form->execute(Bob);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << BLUE "\n--Creating ShrubberyCreationForm--" RESET << std::endl;
			form = Newbie.makeForm("shrubbery creation", "big_tree");
			std::cout << *form << std::endl;
			Bob.signForm(*form);
			std::cout << *form << std::endl;
			form->execute(Bob);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << BLUE "\n--Creating RobotomyRequestForm--" RESET << std::endl;
			form = Newbie.makeForm("robotomy request", "Jack");
			std::cout << *form << std::endl;
			Bob.signForm(*form);
			std::cout << *form << std::endl;
			form->execute(Bob);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << BLUE "\n--Creating Form that does not exist--" RESET << std::endl;
			form = Newbie.makeForm("form that doesn't exist", "Wrong");
			std::cout << *form << std::endl;
			Bob.signForm(*form);
			std::cout << *form << std::endl;
			form->execute(Bob);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
