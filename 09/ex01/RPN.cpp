#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _data(other._data) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_data = other._data;
    return *this;
}

RPN::~RPN() {}

void RPN::result(std::string &equation) {
    if (checkEquation(equation) == false)
        throw InvalidEquationException();
    std::string::iterator it = equation.begin();
    std::string op = "*/-+";
    std::string n;
    std::string trash;
    std::istringstream iss(equation);
    for (; it != equation.end(); it++){
        if ((*it == '-' && std::isdigit(*(it + 1))) || std::isdigit(*it)){
            std::getline(iss, n, ' ');
            this->_data.push(std::stoi(n));
            it += n.size();
        }
        else if (op.find(*it) != std::string::npos){
            if (this->_data.size() < 2)
                throw InvalidEquationException();
            int d1 = this->_data.top();
            this->_data.pop();
            int d2 = this->_data.top();
            this->_data.pop();
            if (*it == '-')
                this->_data.push(d2 - d1);
            if (*it == '+')
                this->_data.push(d2 + d1);
            if (*it == '*')
                this->_data.push(d2 * d1);
            if (*it == '/')
                this->_data.push(d2 / d1);
            std::getline(iss, trash, ' ');
        }
        else
            continue;
    }
    if (this->_data.size() > 1){
        throw InvalidEquationException();
    }
    std::cout << "Result is: " << this->_data.top() << std::endl;
}

bool RPN::checkEquation(std::string &equation) {
    std::string format = " 0123456789+/*-";
    std::string op = "*/-+";
    std::string::iterator it = equation.begin();
    std::string n;
    std::string trash;
    std::istringstream iss(equation);
    int nb;
    for (; it != equation.end(); it++){
        if (format.find(*it) == std::string::npos){
            return false;
        }
        if (*it == '-' && std::isdigit(*(it + 1))){
            std::getline(iss, n, ' ');
            try { nb = std::stoi(n); } catch (std::exception &e){ return false; }
            it += n.size();
        }
        else if (std::isdigit(*it)){
                std::getline(iss, n, ' ');
                try { nb = std::stoi(n); } catch (std::exception &e) { return false; }
                it += n.size();
        }
        else if (op.find(*it) != std::string::npos)
            std::getline(iss, trash, ' ');
    }
    return true;
}

const char *InvalidEquationException::what() const throw() {
    return "Error: invalid equation.";
}
