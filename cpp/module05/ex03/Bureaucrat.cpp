#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(0)
{

}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade)
{
    if (_grade < 0)
        throw GradeTooHighException();
    else if (_grade > 150)
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
    if (grade == 0)
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

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " couldn't sign " << f.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm& f)
{
    try
    {
        f.execute(*this);
        std::cout << name << " executed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << name << " couldn't execute " << f.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return (out);
}
