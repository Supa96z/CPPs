#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &i) {}

Intern &Intern::operator=(const Intern &i) { return (*this); }

Intern::~Intern() {}

AForm* Intern::makePresidential(std::string target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomy(std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubbery(std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string s[3]={"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (Intern::*fp[3])(std::string) = {&Intern::makeRobotomy, &Intern::makePresidential, &Intern::makeShrubbery};
    int i;
    i = 0;
    while (i < 3 && s[i].compare(formName))
        i++;
    if (i < 3){
        std::cout << "Intern creates a " << formName << " form." << std::endl;
        return ((this->*fp[i])(target));
    }
    else
        std::cout << "Error: " << formName << " isn't a valid form name." << std::endl;
    return NULL;
}