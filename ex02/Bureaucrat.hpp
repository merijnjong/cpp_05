/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 13:38:25 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/08/21 10:45:19 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define PINK "\033[95m"
#define RESET "\033[0m"

class	AForm;

class Bureaucrat
{
  public:
	Bureaucrat(const std::string &name, int signGrade, int executeGrade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	void incrementGrade(void);
	void incrementGrade(int increment);
	void decrementGrade(void);
	void decrementGrade(int decrement);
	void signForm(AForm &form);
	void executeForm(AForm const &form) const;

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

  private:
	const std::string _name;
	int _signGrade;
	int _execGrade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat obj);
