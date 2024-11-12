#include <iostream>
#include <cstdio>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phoneBook;
    std::string input;

	std::cout << "Welcome to CPP Module00!\n";
    while (1)
    {
		std::cout << "You can choose 3 types of input.\n";
		std::cout << "1. ADD\t 2. SEARCH\t 3. EXIT\t\n";
        std::cout << "Input: ";
        std::getline(std::cin, input);

        if (input == "ADD")
            phoneBook.add();
        else if (input == "SEARCH")
            phoneBook.search();
        else if (input == "EXIT" || std::cin.eof())
        {
            std::cout << "Program exits.\n";
            return (0);
        }
        else
            std::cout << "Wrong Input!\n\n";
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
		}
    }
    
}