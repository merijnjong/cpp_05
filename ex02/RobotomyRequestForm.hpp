#pragma once

#include "AForm.hpp"
#include <random>

class RobotomyRequestForm : public AForm
{
  private:
	static const int rrSignGrade = 72;
	static const int rrExecGrade = 45;
	std::string _target;

  public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
