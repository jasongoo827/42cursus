#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact arr[8];
    int     idx;
    int     size;
    
public:
    PhoneBook();
    void    add(Contact contact);
    void    search(int index);
    void    printInfo();
};

#endif

