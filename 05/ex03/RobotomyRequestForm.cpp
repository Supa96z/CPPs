#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Unknown", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r.getName(), r.getGradeSign(), r.getGradeExec()), _target(r._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &r) {
    if (this != &r)
        this->_target = r._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    this->AForm::checkRequirements(executor);
    int r = rand() % 2;
    if (r == 0)
        std::cout << "*Drilling noises*. " << this->_target << "has been successfully robotomized." << std::endl;
    else
        std::cout << "*Drilling noises*. " << this->_target << "'s robotomy has failed miserably." << std::endl;
}
