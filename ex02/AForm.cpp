/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:37:02 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/23 12:05:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

AForm::AForm(const std::string &name, int signGrade,
	int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &other) : _name(other._name),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "AForm Copy constructor called!" << std::endl;
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw AForm::FormAlreadySignedException();
	if (this->_signGrade < bureaucrat.getSignGrade())
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (this->_executeGrade < bureaucrat.getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	bureaucrat.executeForm(*this);
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}
bool AForm::getSigned(void) const
{
	return (this->_isSigned);
}
int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}
int AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

const char *AForm::GradeTooHighException::what(void) const noexcept
{
	return (RED "Form grade is too High!" RESET);
}

const char *AForm::GradeTooLowException::what(void) const noexcept
{
	return (RED "Form grade is too Low!" RESET);
}

const char *AForm::FormNotSignedException::what(void) const noexcept
{
	return (RED "Form is not yet signed!" RESET);
}

const char *AForm::FormAlreadySignedException::what(void) const noexcept
{
	return (RED "Form is already signed!" RESET);
}