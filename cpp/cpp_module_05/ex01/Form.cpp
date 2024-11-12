#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name(""), signGrade(1), executeGrade(1), isSigned(false)
{

}

Form::Form(const std::string _name, const int _signGrade, const int _executeGrade):
name(_name), signGrade(_signGrade), executeGrade(_executeGrade), isSigned(false)
{
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other): name(other.name), signGrade(other.signGrade), 
executeGrade(other.executeGrade), isSigned(other.isSigned)
{
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& rhs)
{
    if (this == &rhs)
        return (*this);
    isSigned = rhs.getIsSigned();
    return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
    return name;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecuteGrade() const
{
    return executeGrade;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= signGrade)
        isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
    out << rhs.getName() << ", form sign grade " << rhs.getSignGrade() << ", form execute grade " << rhs.getExecuteGrade();
    if (rhs.getIsSigned())
        out << ", is signed ";
    else
        out << ", is not signed ";
    return (out);
}