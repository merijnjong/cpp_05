#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	static const int ppSignGrade = 25;
	static const int ppExecGrade = 5;
	std::string _target;

  public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
