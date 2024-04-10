#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"


int main(void)
{
    PhoneBook   phoneBook;
    std::string input;

    std::cout << "Welcome to CPP Module00!\n";
    std::cout << "You can choose 3 types of input.\n";
    std::cout << "1. ADD\t 2. SEARCH\t 3. EXIT\t\n";
    while (1)
    {
        std::cout << "Input: ";
        std::cin >> input;

        if (input == "ADD")
        {
            Contact     contact;
            std::string firstName;
            std::string lastName;
            std::string nickname;
            std::string phoneNum;
            std::cout << "Type first name: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);
            std::cout << "Type last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Type nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Type phone number: ";
            std::getline(std::cin, phoneNum);

            if (firstName == "" || lastName == "" || nickname == "" || phoneNum == "")
            {
                std::cout << "Contact field cannot be empty!\n";
                continue ;
            }
            contact.setVariables(firstName, lastName, nickname, phoneNum);
            phoneBook.add(contact);
        }
        else if (input == "SEARCH")
        {
            phoneBook.printInfo();
            int index;
            std::cout << "Which contact are you looking for?\n";
            std::cout <<"Type the index: ";
            std::cin >> index;
            phoneBook.search(index);
        }
        else if (input == "EXIT")
        {
            std::cout << "Program exits.\n";
            return (0);
        }
        else
            std::cout << "Wrong Input!\n";
    }
    
}