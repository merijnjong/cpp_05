/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:37:02 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/23 11:56:18 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

Form::Form(const std::string &name, int signGrade) : _name(name),
	_isSigned(false), _signGrade(signGrade), _executeGrade(1)
{
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Made form " << this->_name << " with sign grade " << this->_signGrade << std::endl;
}

Form::Form(const Form &other) : _name(other._name),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

const std::string Form::getName(void)
{
	return (this->_name);
}
bool Form::getSigned(void) const
{
	return (this->_isSigned);
}
int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}
int Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::setSigned(bool sign)
{
	this->_isSigned = sign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw Form::FormAlreadySignedException();
	if (this->_signGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_isSigned = true;	
}
const char *Form::GradeTooHighException::what(void) const noexcept
{
	return (RED "Form grade is too High!" RESET);
}

const char *Form::GradeTooLowException::what(void) const noexcept
{
	return (RED "Form grade is too Low!" RESET);
}

const char *Form::FormNotSignedException::what(void) const noexcept
{
	return (RED "Form is not yet signed!" RESET);
}

const char *Form::FormAlreadySignedException::what(void) const noexcept
{
	return (RED "Form is already signed!" RESET);
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << "Form " << form.getName() << " has sign grade " << form.getSignGrade();
	os << " and execute grade " << form.getExecuteGrade() << " and is ";
	form.getSigned() ? os << GREEN "signed " RESET : os << RED "not signed " RESET;
	return (os);
}
