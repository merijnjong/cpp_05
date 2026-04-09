#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresedentialPardonForm",
	ppSignGrade, ppExecGrade), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy constructor called!" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

AForm	*PresidentialPardonForm::makeForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << "Informs that " << getTarget() << " has been pardoned by Zaphod Beeblebroxx" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}