#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
void easyfind(T &lst, int n) {
	return ((void)(std::find(lst.begin(), lst.end(), n) == lst.end() ? throw ElementNotFoundException() : (std::cout << "Element found." << std::endl)));
}

const char *ElementNotFoundException::what() const throw() {
	return ("Exception: element not found.");
}

#endif
