#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &p);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const &executor) const;
};

#endif