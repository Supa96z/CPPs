#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown"), _gradeSign(150), _gradeExec(150), _formSigned(false) {}

Form::Form(const Form &f) : _name(f._name), _gradeSign(f._gradeSign), _gradeExec(f._gradeExec), _formSigned(f._formSigned) {}

Form &Form::operator=(const Form &f){
    if (this != &f){
        this->_name = f._name;
        this->_gradeSign = f._gradeSign;
        this->_gradeExec = f._gradeExec;
        this->_formSigned = f._formSigned;
    }
    return *this;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _formSigned(false) {
    if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
        throw GradeTooLow;
    if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
        throw GradeTooHigh;
}

Form::~Form() {}

std::string Form::getName() { return this->_name; }
bool Form::getFormSigned() { return this->_formSigned; }
int Form::getGradeSign() { return this->_gradeSign; }
int Form::getGradeExec() { return this->_gradeExec; }

void Form::beSigned(Bureaucrat b) {
    if (b._grade <= this->_gradeSign)
        this->_formSigned = true;
    else
        throw GradeTooLow;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Oops. Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Oops. Grade too low!");
}

std::ostream& operator<<(std::ostream& os, Form& Form) {
    os << "Form named: " << Form.getName();
    if (Form.getFormSigned() == 1)
        os << " is signed. Grade required to sign it was: " << Form.getGradeSign();
    else
        os << " is unsigned. Grade required to sign it is: " << Form.getGradeSign();
    os << ". Grade required to execute it is: " << Form.getGradeExec() << "." << std::endl;
    return os;
}
