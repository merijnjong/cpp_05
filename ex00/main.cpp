#include "Bureaucrat.hpp"

static void section(const std::string &name)
{
	std::cout << "\n--- " << name << " ---" << std::endl;
}

int main()
{
	section("TEST 1: valid construction + increment/decrement (should succeed)");
	try
	{
		Bureaucrat userA("UserA", 3);
		std::cout << userA << std::endl;
		userA.incrementGrade();
		std::cout << "After increment: " << userA << std::endl;
		userA.decrementGrade();
		std::cout << "After decrement: " << userA << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected failure: " << e.what() << std::endl;
	}

	section("TEST 2: constructor grade 0 (should fail: too high)");
	try
	{
		Bureaucrat userHigh("UserHigh", 0);
		std::cout << userHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected failure: " << e.what() << std::endl;
	}

	section("TEST 3: constructor grade 151 (should fail: too low)");
	try
	{
		Bureaucrat userLow("UserLow", 151);
		std::cout << userLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Expected failure: " << e.what() << std::endl;
	}

	section("TEST 4: increment at grade 1 (should fail)");
	try
	{
		Bureaucrat topUser("TopUser", 1);
		topUser.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Increment blocked at top rank: " << e.what() << std::endl;
	}

	section("TEST 5: decrement at grade 150 (should fail)");
	try
	{
		Bureaucrat lowUser("LowUser", 150);
		lowUser.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Decrement blocked at lowest rank: " << e.what() << std::endl;
	}
	return (0);
}