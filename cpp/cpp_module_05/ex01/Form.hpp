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
    ~Form();

    std::string getName() const;
    int   		getSignGrade() const;
    int   		getExecuteGrade() const;
    bool        getIsSigned() const;
    void        beSigned(const Bureaucrat& b);

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
    const int signGrade;
    const int executeGrade;
    bool isSigned;
    
    Form& operator=(const Form& rhs);
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);


#endif