#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <class T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <class T>
Array<T>::Array(const Array& a) : _data(new T[a._size]), _size(a._size) { copydata(a._data, _data, _size); }

template <class T>
Array<T>& Array<T>::operator=(const Array& a){
	if (this != &a){
		delete[] _data;
		_size = a._size;
		_data = new T[_size];
		copydata(a._data, _data, _size);
	}
	return *this;
}

template <class T>
Array<T>::~Array() {
	delete[] _data;
}

template <class T>
T& Array<T>::operator[](std::size_t index) {
	if (index < 0 || index >= _size) {
		throw OutOfBoundsException();
	}
	return _data[index];
}

template <class T>
std::size_t Array<T>::size() const {
	return _size;
}

template <class T>
void Array<T>::copydata(const T* source, T* destination, std::size_t size){
	for (std::size_t i; i < size; i++)
		destination[i] = source[i];
}

const char *OutOfBoundsException::what() const throw() {
	return ("Out of bounds.");
}

#endif
