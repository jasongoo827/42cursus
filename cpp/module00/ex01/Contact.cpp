#include "Contact.hpp"

Contact::Contact()
{

}

std::string& Contact::getFirstName()
{
    return first_name;
}

std::string& Contact::getLastName()
{
    return last_name;
}

std::string& Contact::getNickName()
{
    return nickname;
}

std::string& Contact::getPhoneNum()
{
    return phone_number;
}

void Contact::setVariables(std::string s1, std::string s2, std::string s3, std::string s4)
{
    first_name = s1;
    last_name = s2;
    nickname = s3;
    phone_number = s4;
}