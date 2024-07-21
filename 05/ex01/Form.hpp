#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
    private:
        std::string _name;
        bool _formSigned;
        int _gradeSign;
        int _gradeExec;

    public:
        /* OCCF */
        Form();
        Form(const Form &f);
        Form &operator=(const Form &f);
        ~Form();

        /* Exercise specific */
        Form(std::string name, int gradeSign, int gradeExec);
        std::string getName();
        bool getFormSigned();
        int getGradeSign();
        int getGradeExec();
        void beSigned(Bureaucrat b);

        class GradeTooHighException : public std::exception {
            const char * what() const throw ();
        } GradeTooHigh;
        class GradeTooLowException : public std::exception {
            const char * what() const throw();
        } GradeTooLow;
};

std::ostream& operator<<(std::ostream& os, Form& Form);

#endif