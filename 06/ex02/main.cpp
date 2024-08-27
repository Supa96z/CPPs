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
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A." << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Type B." << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Type C." << std::endl;
    else 
        std::cout << "Type unknown." << std::endl;
}

void identify(Base &p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "Type A." << std::endl;
        return;
    } catch (const std::exception& e) { (void)e; }

    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "Type B." << std::endl;
        return;
    } catch (const std::exception& e) { (void)e; }

    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "Type C." << std::endl;
        return;
    } catch (const std::exception& e) { (void)e; }

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
