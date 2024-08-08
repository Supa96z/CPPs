#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknown", 145, 137) {}
    
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s.getName(), s.getGradeSign(), s.getGradeExec()), _target(s._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s) {
    if (this != &s)
        this->_target = s._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    this->AForm::checkRequirements(executor);
    std::ofstream file;
    file.open((this->_target + "_shrubbery").c_str());
    if (file.is_open() == false){
        std::cout << executor.getName() << " couldn't execute form " << this->getName() << " because the file in which they were supposed to write trees couldn't be opened." << std::endl;
        throw FileNotOpened;
    }
    file << "               ,@@@@@@@,\n"
            "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            "       |o|        | |         | |\n"
            "       |.|        | |         | |\n"
            "    \\\\ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
    file.close();
}
