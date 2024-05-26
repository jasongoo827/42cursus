#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
    PresidentialPardonForm(std::string _target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    ~PresidentialPardonForm();

    std::string getTarget() const;
    // void        beSigned(const Bureaucrat& b);
    void        execute(const Bureaucrat& executor) const;
private:
    std::string target;

};

#endif