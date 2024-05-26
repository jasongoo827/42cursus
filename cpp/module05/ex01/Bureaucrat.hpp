#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

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
    void        signForm(Form& f);

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

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif