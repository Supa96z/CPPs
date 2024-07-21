#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("James", 150);
        Form f("sui", 150, 150);
        f.beSigned(b);
        b.signForm(f);
        std::cout <<f;
    }
    catch(std::exception& e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
}