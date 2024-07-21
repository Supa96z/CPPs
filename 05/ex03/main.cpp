#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
    try
    {
        std::string target = "pretty";
        Bureaucrat b("john", 1);
        Intern random;
        AForm* s;
        s = random.makeForm("shrubbery creation", "james");
        b.signForm(*s);
        b.executeForm(*s);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}