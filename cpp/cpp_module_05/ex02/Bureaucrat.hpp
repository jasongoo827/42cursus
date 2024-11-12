#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string _name, int _grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;
    void        increaseGrade();
    void        decreaseGrade();
    void        signForm(AForm& f);
    void        executeForm(AForm& f);

public:
    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw();
    };

private:
    const std::string name;
    int grade;

    Bureaucrat& operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif