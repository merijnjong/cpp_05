/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 18:14:45 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/11/04 09:19:13 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern Copy constructor called!" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
	std::cout << "AForm Copy assignment operator called!" << std::endl;
	return (*this);
}

Intern::~Intern()
{
}

template <typename FormType>
AForm* createForm(const std::string& target) {
    return new FormType(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::array<std::pair<std::string, std::function<AForm*()>>, 3> formArray = {{
        {"presidential pardon", [&target]() { return createForm<PresidentialPardonForm>(target); }},
        {"shrubbery creation", [&target]() { return createForm<ShrubberyCreationForm>(target); }},
        {"robotomy request", [&target]() { return createForm<RobotomyRequestForm>(target); }}
    }};

    for (const auto &formPair : formArray) {
        if (formPair.first == formName) {
            return formPair.second();
        }
    }

    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what(void) const noexcept
{
	return (RED "Form has not been found!" RESET);
}