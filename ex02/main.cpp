#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << PINK "\n-- making a Bureaucrat sign a PresidentialPardon --" RESET << std::endl;
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 1);
        PresidentialPardonForm pres = PresidentialPardonForm("The Netherlands");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
	std::cout << PINK "\n-- making a Bureaucrat sign a Robotomy Request --" RESET << std::endl;
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 4);
        RobotomyRequestForm pres = RobotomyRequestForm("Henk");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
	std::cout << PINK "\n-- making a Bureaucrat sign a Shrubbery Creation --" RESET << std::endl;
    try
    {
        Bureaucrat Jack = Bureaucrat("Jack", 1, 1);
        ShrubberyCreationForm pres = ShrubberyCreationForm("Mozambique");
    
        pres.beSigned(Jack);    
        pres.execute(Jack);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
