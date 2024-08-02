#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "Error: no arguments." << std::endl;
        return 0;
    }
    argv++;
    PmergeMe fj;

    try {
        fj.parseSequence(argc, argv);
        fj.sortWithVec();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


    /*std::vector<std::pair<int, int>>::iterator it = this->_data1.begin();
    for (; it != this->_data1.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    if (this->_last)
        std::cout << this->_last << std::endl;*/
