#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name(""), signGrade(0), executeGrade(0), isSigned(false)
{

}

AForm::AForm(const std::string _name, const int _signGrade, const int _executeGrade):
name(_name), signGrade(_signGrade), executeGrade(_executeGrade), isSigned(false)
{
    if (signGrade < 0)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 0)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), signGrade(other.signGrade), 
executeGrade(other.executeGrade), isSigned(other.isSigned)
{
    if (signGrade < 0)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 0)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this == &rhs)
        return (*this);
    return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
    return name;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= signGrade)
        isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

// void    AForm::execute(const Bureaucrat& b) const
// {
//     (void)b;
// }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs)
{
    out << rhs.getName() << ", form sign grade " << rhs.getSignGrade() << ", form execute grade " << rhs.getExecuteGrade() << ", is signed " << rhs.getIsSigned();
    return (out);
}