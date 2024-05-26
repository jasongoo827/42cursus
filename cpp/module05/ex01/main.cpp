#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        std::cout <<"TEST1: Normal Case\n";

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
        std::cout <<"\nTEST2: Form too high Case\n";

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
        std::cout <<"\nTEST3: Form too low Case\n";

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
        std::cout <<"\nTEST4: Form too low for sign Case\n";

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