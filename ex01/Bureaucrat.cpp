#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
	_grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
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
		this->_grade = other._grade;
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

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	incrementGrade(1);
}

void Bureaucrat::incrementGrade(int increment)
{
	if ((this->_grade - increment) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= increment;
}

void Bureaucrat::decrementGrade(void)
{
	decrementGrade(1);
}

void Bureaucrat::decrementGrade(int decrement)
{
	if ((this->_grade + decrement) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += decrement;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his/her grade is too low!" << std::endl;
		return ;
	}
	catch (const Form::FormAlreadySignedException &e)
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
	os << bureaucrat.getGrade() << ". " << std::endl;
	return (os);
}
