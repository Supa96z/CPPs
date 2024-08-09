#include "Serializer.hpp"

int main()
{
    Data* ptr = new Data{42, "Forty2"};
    Data* ptr2 = nullptr;
    std::cout << ptr << std::endl << ptr2 << std::endl;
    uintptr_t raw;
    raw = Serializer::serialize(ptr);
    ptr2 = Serializer::deserialize(raw);
    std::cout << ptr << std::endl << ptr2 << std::endl;
}
