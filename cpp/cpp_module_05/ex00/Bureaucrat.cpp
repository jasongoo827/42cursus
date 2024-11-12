#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this == &rhs)
        return (*this);
    this->grade = rhs.grade;
    // this->name = rhs.name;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::increaseGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (out);
}
