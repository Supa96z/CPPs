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

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    if (grade > MIN_GRADE)
        throw GradeTooLow;
    if (grade < MAX_GRADE)
        throw GradeTooHigh;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() { return this->_grade; }

std::string Bureaucrat::getName() { return this->_name; }

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

void Bureaucrat::signForm(Form &f) {
    if (f.getFormSigned())
        std::cout << this->_name << " couldn't sign " << f.getName() << " because it was already signed." << std::endl;
    else if (f.getGradeSign() < this->_grade)
        std::cout << this->_name << " couldn't sign " << f.getName() << " because its grade is too low." << std::endl;
    else
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << "." << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Oops. Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Oops. Grade too low!");
}

std::ostream& operator<<(std::ostream&  os, Bureaucrat& Bureaucrat) {
    os << Bureaucrat.getName();
    os << ", bureaucrat grade ";
    os << Bureaucrat.getGrade();
    os << "." << std::endl;
    return os;
}

