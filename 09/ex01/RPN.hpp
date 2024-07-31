#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <exception>
# include <sstream>

class RPN {
    private:
        std::stack<int> _data;
        bool checkEquation(std::string &equation);

    public:
        RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);
        ~RPN();

        void result(std::string &equation);
};

class InvalidEquationException : public std::exception {
    const char * what() const throw();
};

#endif
