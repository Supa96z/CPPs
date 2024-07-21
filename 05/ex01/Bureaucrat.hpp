#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
    private:
        std::string _name;

    public:
        /* OCCF */
        Bureaucrat();
        Bureaucrat(const Bureaucrat &b);
        Bureaucrat &operator=(const Bureaucrat &b);
        ~Bureaucrat();
    
        /* Assignment */
        Bureaucrat(std::string name, int grade);
        int getGrade();
        std::string getName();
        void promote();
        void demote();
        void signForm(Form &f);

        int _grade;

        class GradeTooHighException : public std::exception {
            const char * what() const throw ();
        } GradeTooHigh;
        class GradeTooLowException : public std::exception {
            const char * what() const throw();
        } GradeTooLow;

};

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat);

#endif