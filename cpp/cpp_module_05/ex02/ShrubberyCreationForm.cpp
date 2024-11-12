#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
: AForm(_target, 145, 137), target(_target + "_shrubbery")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other.getTarget(), 145, 137), target(other.getTarget() + "_shrubbery")
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this == &rhs)
        return (*this);
    target = rhs.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (getIsSigned() && executor.getGrade() <= getExecuteGrade())
    {
        std::string tree = 
		"          *\n"
        "         / \\\n"
        "        /   \\\n"
        "       /     \\\n"
        "      /       \\\n"
        "     /         \\\n"
        "    /           \\\n"
        "   /             \\\n"
        "  /               \\\n"
        " /                 \\\n"
        "/___________________\\\n"
        "         |||\n"
        "         |||\n"
        "         |||\n";
		
        std::ofstream outfile(target.c_str(), std::ios_base::trunc);
        if (!outfile)
            throw AForm::FileNotOpenedException();
        outfile << tree;
        outfile.close();
    }
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();
}