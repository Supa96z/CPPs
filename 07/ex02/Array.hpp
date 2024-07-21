#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <class T>
class Array
{
    private:
        T myArray[n];

    public:
        Array();
        Array(const Array &a);
        Array &operator=(const Array &a);
        ~Array();

        Array(unsigned int n);
        std::size_t size() const;

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;
        
};

class OutOfBoundsException : public std::exception {
    const char * what() const throw();
};

#include "Array.tpp"

#endif