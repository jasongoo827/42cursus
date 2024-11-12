#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm(std::string _target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    void        execute(const Bureaucrat& executor) const;
private:
    std::string target;

};

#endif