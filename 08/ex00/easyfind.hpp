#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <vector>
# include <list>
# include <deque>
# include <iostream>
# include <algorithm>

template <typename T>
void easyfind(T &lst, int n);

class ElementNotFoundException : public std::exception {
	const char * what() const throw();
};

# include "easyfind.tpp"

#endif
