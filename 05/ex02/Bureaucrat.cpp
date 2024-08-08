#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b._name), _grade(b._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
    if (this != &b){
        this->_name = b._name;
        this->_grade = b._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade > MIN_GRADE)
        throw GradeTooLow;
    if (grade < MAX_GRADE)
        throw GradeTooHigh;
}

int Bureaucrat::getGrade() const { return this->_grade; }

std::string Bureaucrat::getName() const { return this->_name; }

void Bureaucrat::promote() {
    if (this->_grade == MAX_GRADE)
        throw GradeTooHigh;
    else
        this->_grade -= 1;
}

void Bureaucrat::demote() {
    if (this->_grade == MIN_GRADE)
        throw GradeTooLow;
    else
        this->_grade += 1;
}

void Bureaucrat::signForm(AForm &f) {
    if (f.getFormSigned()){
        std::cout << this->_name << " couldn't sign " << f.getName() << " because it was already signed." << std::endl;
        throw FormAlreadySigned;
    }
    else if (f.getGradeSign() < this->_grade){
        std::cout << this->_name << " couldn't sign " << f.getName() << " because its grade is too low." << std::endl;
        throw GradeTooLow;
    }
    else
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed form " << f.getName() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    form.checkRequirements(*this);
    form.execute(*this);
    std::cout << this->getName() << " executed form " << form.getName() << "." << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Oops. Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Oops. Grade too low!");
}

const char *Bureaucrat::FormNotSignedException::what() const throw() {
    return ("Oops. Form not signed!");
}

const char *Bureaucrat::FormAlreadySignedException::what() const throw() {
    return ("Oops. Form already signed!");
}

std::ostream& operator<<(std::ostream&  os, Bureaucrat& Bureaucrat) {
    os << Bureaucrat.getName();
    os << ", bureaucrat grade ";
    os << Bureaucrat.getGrade();
    os << "." << std::endl;
    return os;
}

