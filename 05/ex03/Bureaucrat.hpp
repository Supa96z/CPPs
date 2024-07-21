#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

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

        /* Rest */
        Bureaucrat(std::string name, int grade);

        int getGrade() const;
        std::string getName() const;
        void promote();
        void demote();
        void signForm(AForm &f);
        void executeForm(AForm const & form);

        int _grade;

        class GradeTooHighException : public std::exception {
            const char * what() const throw ();
        } GradeTooHigh;
        class GradeTooLowException : public std::exception {
            const char * what() const throw();
        } GradeTooLow;
        class FormNotSignedException : public std::exception {
            const char * what() const throw();
        } FormNotSigned;
        class FormAlreadySignedException : public std::exception {
            const char * what() const throw();
        } FormAlreadySigned;

};

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat);

#endif