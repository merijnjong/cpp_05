#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int signGrade,
	int executeGrade) : _name(name), _signGrade(signGrade),
	_execGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_signGrade = other._signGrade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Bureaucrat::getExecuteGrade(void) const
{
	return (this->_execGrade);
}

void Bureaucrat::executeForm(AForm const &form) const
{
	if (!form.getSigned())
		throw AForm::FormNotSignedException();
	if (form.getExecuteGrade() < this->_execGrade)
		throw AForm::GradeTooLowException();
	std::cout << this->_name << " executed " << form.getName() << std::endl;
	form.executeForm();
}

void Bureaucrat::incrementGrade(void)
{
	incrementGrade(1);
}

void Bureaucrat::incrementGrade(int increment)
{
	if ((this->_signGrade - increment) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_signGrade -= increment;
}

void Bureaucrat::decrementGrade(void)
{
	decrementGrade(1);
}

void Bureaucrat::decrementGrade(int decrement)
{
	if ((this->_signGrade + decrement) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_signGrade += decrement;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his/her grade is too low!" << std::endl;
		return ;
	}
	catch (const AForm::FormAlreadySignedException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because this form is already signed!" << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;;
}

const char *Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return (RED "Grade is too High!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return (RED "Grade is too Low!" RESET);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade ";
	os << bureaucrat.getSignGrade() << ". " << std::endl;
	return (os);
}
