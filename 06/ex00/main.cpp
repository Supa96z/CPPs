#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cout << "Allez fait un effort, c'est pas complique de mettre un seul argument --'" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}
