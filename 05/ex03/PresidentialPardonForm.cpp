#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Unknown", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p.getName(), p.getGradeSign(), p.getGradeExec()), _target(p._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p) { return (*this); }

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    this->AForm::checkRequirements(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}