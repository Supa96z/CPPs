#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("James", 150);
        std::cout <<b;
        b.promote();
        std::cout <<b;
        b.demote();
        std::cout <<b;
        b.demote();
        std::cout <<b;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
}