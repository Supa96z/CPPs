#include "iter.hpp"

void incrementI(int& n){
    n += 1;
}

void incrementD(double& n){
    n += 1;
}

int main()
{
    int arrayI[] = {1,2,3,4,5,6,7,8,9};
    double arrayD[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};

    for (int i = 0; i < 9; i++)
        std::cout << arrayI[i] << " ";
    std::cout << std::endl;
    iter(arrayI, incrementI);
    for (int i = 0; i < 9; i++)
        std::cout << arrayI[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 9; i++)
        std::cout << arrayD[i] << " ";
    std::cout << std::endl;
    iter(arrayD, incrementD);
    for (int i = 0; i < 9; i++)
        std::cout << arrayD[i] << " ";
    std::cout << std::endl;
}