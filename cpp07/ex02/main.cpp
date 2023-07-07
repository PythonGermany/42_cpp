#include <stdlib.h>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> test;

	try
	{
		std::cout << test[0] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << std::endl;
	test = numbers;
	Array<int> tmp(test);
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i] || mirror[i] != test[i] || mirror[i] != tmp[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = -1;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (numbers[i] == test[i] || numbers[i] == tmp[i])
		{
			std::cerr << "Operation changed all values!!" << std::endl;
			return 1;
		}
	}
	delete[] mirror; //
	return 0;
}