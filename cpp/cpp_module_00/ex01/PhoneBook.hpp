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
	~PhoneBook();
    void    add();
    void    search();
    void    printInfo();
};

#endif

