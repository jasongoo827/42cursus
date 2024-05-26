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
    virtual ~AForm();

    std::string     getName() const;
    int             getSignGrade() const;
    int             getExecuteGrade() const;
    bool            getIsSigned() const;
    void            beSigned(const Bureaucrat& b);
    virtual void    execute(const Bureaucrat& executor) const = 0;

public:
    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw();
    };

    class FormNotSignedException: public std::exception
    {
        virtual const char* what() const throw();
    };

private:
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool isSigned;

};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif