#include "iter.hpp"

void multiply_element(int& num)
{
	num *= 2;
}

void print_element(const int& num)
{
	std::cout << num << " ";
}

int int_multiply_element(int& num)
{
	num *= 2;
	return (num);
}

const int& int_multiply_element2(int& num)
{
	num *= 2;
	return (num);
}

int main(void)
{
	// test case 1
	int arr[4] = {1, 2, 3, 4};

	std::cout << "TEST CASE 1: iter - void multiply_element(int& )\n";
	std::cout << "int array {1, 2, 3, 4}\n";
	::iter(arr, 4, multiply_element);
	for (int i = 0; i < 4; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	// test case 2
	const int arr2[4] = {1, 2, 3, 4};

	std::cout << "\nTEST CASE 2: iter - void print_element(const int& )\n";
	std::cout << "const int array {1, 2, 3, 4}\n";
	::iter(arr2, 4, print_element);
	std::cout << "\n";

	// test case 3
	int arr3[4] = {11, 22, 33, 44};

	std::cout << "\nTEST CASE 3: iter - int int_multiply_element(int& )\n";
	std::cout << "int array {11, 22, 33, 44}\n";
	::iter(arr3, 4, int_multiply_element);
	for (int i = 0; i < 4; ++i)
		std::cout << arr3[i] << " ";
	std::cout << "\n";

	// test case 4
	int arr4[4] = {11, 22, 33, 44};

	std::cout << "\nTEST CASE 4: iter - const int& int_multiply_element2(int& )\n";
	std::cout << "int array {11, 22, 33, 44}\n";
	::iter(arr4, 4, int_multiply_element2);
	for (int i = 0; i < 4; ++i)
		std::cout << arr4[i] << " ";
	std::cout << "\n";
}