#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include <fstream>

class Bureaucrat;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class AForm
{
    private:
        std::string _name;
        bool _formSigned;
        int _gradeSign;
        int _gradeExec;

    public:
        /* OCCF */
        AForm();
        AForm(const AForm &f);
        AForm &operator=(const AForm &f);
        ~AForm();

        /* Assignment */
        AForm(std::string name, int gradeSign, int gradeExec);
        std::string getName() const;
        bool getFormSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat b);
        void checkRequirements(Bureaucrat const &executor) const;
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception {
            const char * what() const throw ();
        } GradeTooHigh;

        class GradeTooLowException : public std::exception {
            const char * what() const throw();
        } GradeTooLow;

        class FormNotSignedException : public std::exception {
            const char * what() const throw();
        } FormNotSigned;

        class FileNotOpenedException : public std::exception {
            const char * what() const throw();
        } FileNotOpened;

};

std::ostream& operator<<(std::ostream& os, AForm& Form);

#endif