#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    // darkest secret?
public:
    Contact();
    std::string& getFirstName();
    std::string& getLastName();
    std::string& getNickName();
    std::string& getPhoneNum();
    void         setVariables(std::string s1, std::string s2, std::string s3, std::string s4);
};

#endif

