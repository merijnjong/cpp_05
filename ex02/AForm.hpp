/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:36:00 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/08/21 10:45:07 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define BLUE "\033[94m"
#define PINK "\033[95m"
#define RESET "\033[0m"

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _executeGrade;

  public:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm &operator=(const AForm &other);
	AForm(const AForm &other);
	~AForm();
	const std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
	virtual std::string getTarget(void) const = 0;
	virtual void executeForm(void) const = 0;
	
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
	class FormNotSignedException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
	class FormAlreadySignedException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
};
