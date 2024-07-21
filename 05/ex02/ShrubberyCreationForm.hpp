#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &s);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &s);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const &executor) const;
};

#endif