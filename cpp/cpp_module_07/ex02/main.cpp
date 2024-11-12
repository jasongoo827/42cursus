#include "Array.hpp"

// void check_leak(void)
// {
// 	system("leaks ex02");
// }

int main(void)
{
	// atexit(check_leak);
	std::cout << "TEST CASE 1: check normal case\n";
	{
		std::cout << "Array<int> array(10)\n";
		Array<int> array(10);
		std::cout << "array[3] = " << array[3] << std::endl;
		std::cout << "\ninitialize array\n";
		for (int i = 0; i < 10; ++i)
			array[i] = i;
		std::cout << "Array => ";
		for (int i = 0; i < 10; ++i)
			std::cout << array[i] << " ";
		std::cout << "\n";
	}

	std::cout << "\nTEST CASE 2: check [] operator && memory\n";
	{
		Array<int> array;
		try
		{
			array[2] = 3;
		}
		catch(const std::exception& e)
		{
			std::cerr << "index is out of range!\n";
		}
	}
	
	std::cout << "\nTEST CASE 3: check copy constructor\n";
	{
		std::cout << "Array<char> array(10)\n";
		Array<char> array(10);
		std::cout << "Initialize array to a ~ j\n";
		for (int i = 0; i < 10; ++i)
			array[i] = 'a' + i;

		std::cout << "\ncopy array by copy constructor\n";
		std::cout << "Array<char> copy(array)\n";
		Array<char> copy(array);
		for (int i = 0; i < 10; ++i)
			std::cout << copy[i];
		std::cout << "\n";

		std::cout << "\ncheck deep copy\n";
		for (int i = 0; i < 10; ++i)
		{
			if (&array[i] == &copy[i])
				std::cout << "same!\n";
			else
				std::cout << "different!\n";
		}
	}

	std::cout << "\nTEST CASE 4: check copy operator\n";
	{
		std::cout << "Array<std::string> array(10)\n";
		Array<std::string> array(10);
		std::cout << "Initialize array to jgoo\n";
		for (int i = 0; i < 10; ++i)
			array[i] = "jgoo";

		std::cout << "\ncopy array by copy operator\n";
		std::cout << "Array<std::string> copy\n";
		std::cout << "copy = array\n";
		Array<std::string> copy;
		copy = array;
		for (int i = 0; i < 10; ++i)
			std::cout << copy[i];
		std::cout << "\n";

		std::cout << "\ncheck deep copy\n";
		for (int i = 0; i < 10; ++i)
		{
			if (&array[i] == &copy[i])
				std::cout << "same!\n";
			else
				std::cout << "different!\n";
		}
	}
}