#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
    private:

    std::string _name;

    class GradeTooHighException : public std::exception {
        const char * what() const throw () {}
    } GradeTooHigh;

    class GradeTooLowException : public std::exception {
        const char * what() const throw() {}
    } GradeTooLow;

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

    int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat);

#endif