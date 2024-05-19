#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("jgoo", 100);
        std::cout << a << std::endl;

        Form f("42 form", 120, 120);
        std::cout << f << std::endl;

        a.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat a("jgoo", 100);
        std::cout << a << std::endl;

        Form f("42 form", -1, 120);
        std::cout << f << std::endl;

        a.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
        Bureaucrat a("jgoo", 100);
        std::cout << a << std::endl;

        Form f("42 form", 180, 120);
        std::cout << f << std::endl;

        a.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat a("jgoo", 100);
        std::cout << a << std::endl;

        Form f("42 form", 90, 120);
        std::cout << f << std::endl;

        a.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}