#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
: AForm(_target, 72, 45), target(_target + "_robotomy")
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other.getTarget(), 72, 45), target(other.getTarget() + "_robotomy")
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this == &rhs)
        return (*this);
    target = rhs.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

// void RobotomyRequestForm::beSigned(const Bureaucrat& b)
// {

// }

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (getIsSigned() && executor.getGrade() <= getExecuteGrade())
    {
        std::cout << "Dddddrriiiiiillllllllllllll\n";
        std::srand(std::time(NULL));
        int randVal = std::rand();
        if (randVal & 2)
            std::cout << target << " robotomized successfully.\n";
        else
            std::cout << target << " robotomy failed\n";
    }
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
}