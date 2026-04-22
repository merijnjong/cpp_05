#include "Bureaucrat.hpp"
#include "Form.hpp"

static void section(const std::string &name)
{
	std::cout << "\n--- " << name << " ---" << std::endl;
}

int main(void)
{
	section("TEST 1: signing with enough rank (should succeed)");
	try
	{
		Form formA("FormA", 30);
		Bureaucrat userA("UserA", 10);
		std::cout << formA << std::endl;
		userA.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	section("TEST 2: signing with low rank (should fail)");
	try
	{
		Form formB("FormB", 3);
		Bureaucrat userB("UserB", 100);
		userB.signForm(formB);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected failure: " << e.what() << std::endl;
	}

	section("TEST 3: same form signed twice (second should fail)");
	try
	{
		Form formC("FormC", 60);
		Bureaucrat userC("UserC", 20);
		userC.signForm(formC);
		userC.signForm(formC);
		std::cout << formC << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	section("TEST 4: invalid form construction (should fail)");
	try
	{
		Form formInvalid("FormInvalid", 0);
		std::cout << formInvalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Expected failure: " << e.what() << std::endl;
	}
	return (0);
}
