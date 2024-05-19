#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const std::string _name, const int _signGrade, const int _executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    ~Form();

    std::string getName() const;
    int   getSignGrade() const;
    int   getExecuteGrade() const;
    bool        getIsSigned() const;
    void        beSigned(const Bureaucrat& b);

private:
    const std::string name;
    const int signGrade;
    const int executeGrade;
    bool isSigned;

     class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Form Grade is too high!";
        }
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "Form Grade is too low!";
        }
    };
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);


#endif