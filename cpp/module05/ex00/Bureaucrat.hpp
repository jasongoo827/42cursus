#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string _name, int _grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;
    void        increaseGrade();
    void        decreaseGrade();

private:
    const std::string name;
    int grade;

    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade is too low!";
        }
    };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif