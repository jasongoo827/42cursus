#include "RobotomyRequestForm.hpp"

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

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat& b)
{

}

void RobotomyRequestForm::execute(const Bureaucrat& executor)
{

}