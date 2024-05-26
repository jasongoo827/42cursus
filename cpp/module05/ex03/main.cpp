#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
   Intern someRandomIntern;
   AForm* rrf;

   rrf = someRandomIntern.makeForm("robotomy request", "Bender");
   
   Bureaucrat a("jgoo", 10);
   a.signForm(*rrf);
   a.executeForm(*rrf);
   delete rrf;
}