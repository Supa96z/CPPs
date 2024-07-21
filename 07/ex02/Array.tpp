#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <class T>
Array<T>::Array() : _data(nullptr), _size(0); {}

template <class T>
Array<T>::Array(const Array& a) : _data(new T[a._data], _size(a._size)) { copydata(a._data, _data, _size); }


#endif