#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Error: bad arguments." << std::endl;
        return 0;
    }

    RPN rpn;
    std::string equation = argv[1];

    try {
        rpn.result(equation);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}
