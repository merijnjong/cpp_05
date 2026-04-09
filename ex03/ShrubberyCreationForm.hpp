#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>

#define TREE \
"      /\\      \n" \
"     /\\*\\     \n" \
"    /\\O\\*\\    \n" \
"   /*/\\/\\/\\   \n" \
"  /\\O\\/\\*\\/\\  \n" \
" /\\*\\/\\*\\/\\/\\ \n" \
"/\\O\\/\\/*/\\/O/\\ \n" \
"      ||      \n" \
"      ||      \n" \
"      ||      \n"

class ShrubberyCreationForm : public AForm
{
  private:
	static const int scSignGrade = 145;
	static const int scExecGrade = 137;
	std::string _target;

  public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	std::string getTarget(void) const;
	void executeForm(void) const;
};
