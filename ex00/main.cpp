/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:10:28 by mjong             #+#    #+#             */
/*   Updated: 2025/11/06 15:10:31 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        Bureaucrat high("TooHigh", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("TooLow", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat max("Max", 1);
        max.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}