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
	std::string	darkest_secret;
	
public:
    Contact();
	~Contact();
    std::string	getFirstName() const;
    std::string	getLastName() const;
    std::string	getNickName() const;
    std::string	getPhoneNum() const;
    std::string	getDarkestSecret() const;
	void		setFirstName(std::string s);
	void		setLastName(std::string s);
	void		setNickName(std::string s);
	void		setPhoneNum(std::string s);
	void		setDarkestSecret(std::string s);
};

#endif

