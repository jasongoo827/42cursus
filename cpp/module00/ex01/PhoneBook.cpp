#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): idx(0), size(0)
{

}

void PhoneBook::add(Contact contact)
{
    if (idx > 8)
        idx -= 8;
    if (size < 8)
        size++;
    arr[idx] = contact;
}

void PhoneBook::search(int index)
{
    if (index < 1 || index > 8 || index > size)
    {
        std::cout << "Index is out of range\n";
        return ;
    }
    std::cout << arr[index - 1].getFirstName() << std::endl;
    std::cout << arr[index - 1].getLastName() << std::endl;
    std::cout << arr[index - 1].getNickName() << std::endl;
    std::cout << arr[index - 1].getPhoneNum() << std::endl;
}

void PhoneBook::printInfo()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        std::cout << std::setw(10) << arr[i].getFirstName();
        std::cout << "|";
        std::cout << std::setw(10) << arr[i].getLastName();
        std::cout << "|";
        std::cout << std::setw(10) << arr[i].getNickName();
        std::cout << std::endl;
    }
}