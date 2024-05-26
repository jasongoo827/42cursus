#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
   try
   {
    std::cout <<"TEST1: ShrubberyCreationForm\n";
    Bureaucrat a("jgoo", 100);
    ShrubberyCreationForm sf("Form");

    a.signForm(sf);
    a.executeForm(sf);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST2: RobotomyRequestForm\n";
    Bureaucrat a("jgoo", 40);
    RobotomyRequestForm f("Form");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   try
   {
    std::cout <<"\nTEST3: PresidentialPardonForm\n";
    Bureaucrat a("jgoo", 1);
    PresidentialPardonForm f("Form");

    a.signForm(f);
    a.executeForm(f);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
}