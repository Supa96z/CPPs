#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &i);
        Intern &operator=(const Intern &i);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target);
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);
};

#endif