#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    func[0] = &Intern::makeShrubberyCreation;
    func[1] = &Intern::makeRobotomyRequest;
    func[2] = &Intern::makePresidentialPardon;
}

Intern::Intern(const Intern& other)
{
    for (int i = 0; i < 3; ++i)
        func[i] = other.func[i];
}

Intern& Intern::operator=(const Intern& rhs)
{
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < 3; ++i)
        func[i] = rhs.func[i];
    return (*this);
}

Intern::~Intern()
{
    
}


AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; ++i)
    {
        if (name == forms[i])
            return (this->*func[i])(target);
    }
    std::cout <<"I can't make the form!\n";
    return (NULL);
}

AForm* Intern::makeShrubberyCreation(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequest(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardon(std::string target)
{
    return (new PresidentialPardonForm(target));
}