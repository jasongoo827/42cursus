#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
: AForm(_target, 145, 137), target(_target + "_shrubbery")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other.getTarget(), 145, 137), target(other.getTarget() + "_shrubbery")
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)
{

}