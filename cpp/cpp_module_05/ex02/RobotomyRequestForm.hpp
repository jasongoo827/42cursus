#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
    RobotomyRequestForm(std::string _target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    ~RobotomyRequestForm();

    std::string getTarget() const;
    void        execute(const Bureaucrat& executor) const;

public:
	class RobotomyFailException: public std::exception
    {
        virtual const char* what() const throw();
    };
	
private:
    std::string target;

};

#endif