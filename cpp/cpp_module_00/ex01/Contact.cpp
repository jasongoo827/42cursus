#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{
	
}

std::string Contact::getFirstName() const
{
    return first_name;
}

std::string Contact::getLastName() const
{
    return last_name;
}

std::string Contact::getNickName() const
{
    return nickname;
}

std::string Contact::getPhoneNum() const
{
    return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}

void Contact::setFirstName(std::string s)
{
    first_name = s;
}

void Contact::setLastName(std::string s)
{
    last_name = s;
}

void Contact::setNickName(std::string s)
{
    nickname = s;
}

void Contact::setPhoneNum(std::string s)
{
    phone_number = s;
}

void Contact::setDarkestSecret(std::string s)
{
	darkest_secret = s;
}