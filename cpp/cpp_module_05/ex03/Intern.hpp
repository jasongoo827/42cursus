#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& rhs);
    ~Intern();

    AForm* makeForm(std::string name, std::string target);

private:
    AForm* (Intern::*func[3])(std::string target);
    AForm*  makeShrubberyCreation(std::string target);
    AForm*  makeRobotomyRequest(std::string target);
    AForm*  makePresidentialPardon(std::string target);
};

#endif
