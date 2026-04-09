/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 14:32:03 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/24 11:31:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm",
	rrSignGrade, rrExecGrade), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy constructor called!" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::executeForm(void) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<> dist(0, 1);

	bool chance = dist(rng);

	std::cout << BLUE "* DRILLING NOISES *" RESET << std::endl;
	if (chance)
		std::cout << GREEN << this->getTarget() <<  " has been robotomized!" RESET << std::endl;
	else
		std::cout << RED << this->getTarget() << " has failed to be robotomized!" RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}