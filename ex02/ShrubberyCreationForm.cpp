/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:10 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/23 11:58:12 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	scSignGrade, scExecGrade), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy constructor called!" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Problem with opening file in ShrubberyCreationForm" << std::endl;
		return ;
	}

	file << TREE;
	if (!file) {
        std::cerr << "Problem with writing to file in ShrubberyCreationForm" << std::endl;
        return;
    }
	file.close();
	
	std::cout << "Shrubbery Creation made " << filename << " with a tree inside!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}