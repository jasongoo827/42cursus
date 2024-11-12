#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

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
    if (this == &rhs)
        return (*this);
    target = rhs.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (getIsSigned() && executor.getGrade() <= getExecuteGrade())
        std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
}