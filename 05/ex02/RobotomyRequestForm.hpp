#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &r);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
        ~RobotomyRequestForm();

        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const &executor) const;
};

#endif