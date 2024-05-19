#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
: AForm(_target, 25, 5), target(_target + "_presidential")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other.getTarget(), 25, 5), target(other.getTarget() + "_presidential")
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}
void PresidentialPardonForm::beSigned(const Bureaucrat& b)
{

}

void PresidentialPardonForm::execute(const Bureaucrat& executor)
{

}