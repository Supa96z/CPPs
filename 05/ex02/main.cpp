#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    try
    {
        std::string target = "pretty";
        Bureaucrat b("john", 140);
        ShrubberyCreationForm s(target);
        b.signForm(s);
        b.executeForm(s);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}