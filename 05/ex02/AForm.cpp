#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _gradeSign(150), _gradeExec(150), _formSigned(false) {}

AForm::AForm(const AForm &f) : _name(f._name), _gradeSign(f._gradeSign), _gradeExec(f._gradeExec), _formSigned(f._formSigned) {}

AForm &AForm::operator=(const AForm &f) { return (*this); }

AForm::~AForm() {}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _formSigned(false) {
    if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
        throw GradeTooLow;
    if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
        throw GradeTooHigh;
}

std::string AForm::getName() const { return this->_name; }
bool AForm::getFormSigned() const { return this->_formSigned; }
int AForm::getGradeSign() const { return this->_gradeSign; }
int AForm::getGradeExec() const { return this->_gradeExec; }

void AForm::beSigned(Bureaucrat b) {
    if (b._grade <= this->_gradeSign)
        this->_formSigned = true;
    else
        throw GradeTooLow;
}

void AForm::checkRequirements(Bureaucrat const &executor) const {
    if (this->_formSigned == false){
        std::cout << executor.getName() << " couldn't execute form " << this->getName() << " because it was not signed beforehand." << std::endl;
        throw FormNotSigned;
    }
    if (executor.getGrade() > this->_gradeExec){
        std::cout << executor.getName() << " couldn't execute form " << this->getName() << " because his grade is too low." << std::endl;
        throw GradeTooLow;
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Oops. Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Oops. Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Oops. Form not signed!");
}

const char *AForm::FileNotOpenedException::what() const throw() {
    return ("Oops. File not opened!");
}

std::ostream& operator<<(std::ostream& os, AForm& Form) {
    os << "Form named: " << Form.getName();
    if (Form.getFormSigned() == 1)
        os << " is signed. Grade required to sign it was: " << Form.getGradeSign();
    else
        os << " is unsigned. Grade required to sign it is: " << Form.getGradeSign();
    os << ". Grade required to execute it is: " << Form.getGradeExec() << "." << std::endl;
    return os;
}