#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string _name, const int _signGrade, const int _executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    ~AForm();

    std::string     getName() const;
    int             getSignGrade() const;
    int             getExecuteGrade() const;
    bool            getIsSigned() const;
    virtual void    beSigned(const Bureaucrat& b) const = 0;
    virtual void    execute(const Bureaucrat& executor) const = 0;

private:
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool isSigned;

    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "AForm Grade is too high!";
        }
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "AForm Grade is too low!";
        }
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif