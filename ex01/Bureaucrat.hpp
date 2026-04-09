#pragma once

#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class	Form;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void incrementGrade(int increment);
	void decrementGrade(void);
	void decrementGrade(int decrement);
	void signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);
