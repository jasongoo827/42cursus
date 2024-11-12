#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): idx(0), size(0)
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add()
{
	Contact     contact;
	std::string input;

	std::cout << "Type first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);
	if (std::cin.eof() || input == "")
	{
		std::cout << "Contact field cannot be empty!\n\n";
		return ;
	}
	std::cout << "Type last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);
	if (std::cin.eof() || input == "")
	{
		std::cout << "Contact field cannot be empty!\n\n";
		return ;
	}
	std::cout << "Type nickname: ";
	std::getline(std::cin, input);
	contact.setNickName(input);
	if (std::cin.eof() || input == "")
	{
		std::cout << "Contact field cannot be empty!\n\n";
		return ;
	}
	std::cout << "Type phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNum(input);
	if (std::cin.eof() || input == "")
	{
		std::cout << "Contact field cannot be empty!\n\n";
		return ;
	}
	std::cout << "Type Darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	if (std::cin.eof() || input == "")
	{
		std::cout << "Contact field cannot be empty!\n\n";
		return ;
	}
    if (idx >= 8)
        idx -= 8;
    if (size < 8)
        size++;
    arr[idx++] = contact;
}

void PhoneBook::search()
{
	int index;

	if (size == 0)
	{
		std::cout << "Phonebook is empty\n\n";
		return ;
	}
	printInfo();
	std::cout << "Which contact are you looking for?\n";
	std::cout << "Type the index: ";
	std::cin >> index;

    if (index < 1 || index > 8 || index > size || std::cin.eof())
    {
        std::cout << "Index is out of range\n\n";
		std::cin.clear(); 
		std::cin.ignore();
        return ;
    }
    std::cout << "First name: " << arr[index - 1].getFirstName() << std::endl;
    std::cout << "Last name: " << arr[index - 1].getLastName() << std::endl;
    std::cout << "Nick name: " << arr[index - 1].getNickName() << std::endl;
    std::cout << "Phone number: " << arr[index - 1].getPhoneNum() << std::endl;
    std::cout << "Darkest secret: " << arr[index - 1].getDarkestSecret() << std::endl;
	std::cin.ignore();
}

void PhoneBook::printInfo()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
		if (arr[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << arr[i].getFirstName().substr(0, 9) + ".";
		else
        	std::cout << std::setw(10) << arr[i].getFirstName();
        std::cout << "|";
		if (arr[i].getLastName().length() > 10)
			std::cout << std::setw(10) << arr[i].getLastName().substr(0, 9) + ".";
		else	
        	std::cout << std::setw(10) << arr[i].getLastName();
        std::cout << "|";
		if (arr[i].getNickName().length() > 10)
			std::cout << std::setw(10) << arr[i].getNickName().substr(0, 9) + ".";
		else
        	std::cout << std::setw(10) << arr[i].getNickName();
		std::cout << "|";
        std::cout << std::endl;
    }
}