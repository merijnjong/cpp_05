#pragma once

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <array>
#include <functional>

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm *makeForm(const std::string &formName, const std::string &target);
	class FormNotFoundException : public std::exception
	{
		public:
		const char *what(void) const noexcept override;
	};
};
