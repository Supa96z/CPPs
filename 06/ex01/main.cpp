#include "Serializer.hpp"

int main()
{
    Data* ptr = new Data;
    ptr->i = 42;
    ptr->s = "Forty2";
    Data* ptr2 = NULL;
    std::cout << "ptr : " << ptr << std::endl << "ptr2 : " << ptr2 << std::endl;
    uintptr_t raw;
    raw = Serializer::serialize(ptr);
    ptr2 = Serializer::deserialize(raw);
    std::cout << "ptr : " << ptr << "   i : " << ptr->i << "   s : " << ptr->s << "\n";
    std::cout << "ptr2 : " << ptr2 << "   i : " << ptr2->i << "   s : " << ptr2->s << "\n";
}
