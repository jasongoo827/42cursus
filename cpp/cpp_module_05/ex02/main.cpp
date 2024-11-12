#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
   try
   {
    std::cout <<"TEST1-1: ShrubberyCreationForm\n";
    Bureaucrat a("jgoo", 100);
    ShrubberyCreationForm sf("ShrubberyCreationForm");

    a.signForm(sf);
    a.executeForm(sf);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST1-2: ShrubberyCreationForm\n";
    Bureaucrat a("jgoo", 150);
    ShrubberyCreationForm sf("ShrubberyCreationForm");

    a.signForm(sf);
    a.executeForm(sf);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST2-1: RobotomyRequestForm\n";
    Bureaucrat a("jgoo", 40);
    RobotomyRequestForm f("RobotomyRequestForm");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST2-2: RobotomyRequestForm\n";
    Bureaucrat a("jgoo", 80);
    RobotomyRequestForm f("RobotomyRequestForm");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST3-1: PresidentialPardonForm\n";
    Bureaucrat a("jgoo", 1);
    PresidentialPardonForm f("PresidentialPardonForm");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
	std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST3-2: PresidentialPardonForm\n";
    Bureaucrat a("jgoo", 30);
    PresidentialPardonForm f("PresidentialPardonForm");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
	std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST3-3: PresidentialPardonForm\n";
    Bureaucrat a("jgoo", 20);
    Bureaucrat b("yakim", 10);
    PresidentialPardonForm f("PresidentialPardonForm");

    a.signForm(f);
    b.executeForm(f);
   }
   catch(const std::exception& e)
   {
	std::cerr << e.what() << '\n';
   }
}