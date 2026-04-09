/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 16:35:17 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/07/23 11:33:12 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << PINK "\n-- making a Bureaucrat with the right grade sign a form --" RESET << std::endl;
    try
    {
        Form form = Form("*important document*", 150);
        Bureaucrat Jack = Bureaucrat("Jack", 24);
        std::cout << form << std::endl;
        Jack.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    
	std::cout << PINK "\n-- making a Bureaucrat sign a form twice --" RESET << std::endl;
    try
    {
        Form form = Form("*important document*", 125);
        Bureaucrat john = Bureaucrat("John", 125);

        john.signForm(form);
        john.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    
	std::cout << PINK "\n-- making a Bureaucrat with a too low grade sign a form --" RESET << std::endl;
    try
    {
        Form form = Form("*important document*", 4);
        Bureaucrat john = Bureaucrat("John", 50);

        john.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
