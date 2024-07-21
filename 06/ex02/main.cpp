#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <ctime>

Base* generate(void)
{
    switch (std::rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A." << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "Type B." << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "Type C." << std::endl;
    else 
        std::cout << "Type unknown." << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type A." << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type B." << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type C." << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    std::cout << "Type unknown." << std::endl;
}

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *p = generate();
    identify(p);
    identify(*p);

    delete p;
}