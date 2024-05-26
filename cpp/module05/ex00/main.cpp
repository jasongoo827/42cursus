#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout <<"TEST1: Subject Case\n";
        Bureaucrat a("jgoo", 5);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout <<"\nTEST2: Grade too high error\n";
        std::cout <<"Bureaucrat a(\"jgoo\", -1): ";
        Bureaucrat a("jgoo", -1);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout <<"\nTEST3: Grade too low error\n";
        std::cout <<"Bureaucrat a(\"jgoo\", 151): ";
        Bureaucrat a("jgoo", 151);
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}