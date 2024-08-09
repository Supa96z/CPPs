#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <exception>
# include <limits>


class Span {
	private:
		std::vector<int> _data;
		unsigned int _sizeMax;
		Span();

	public:
		Span(const Span& s);
		Span &operator=(const Span& s);
		~Span();

		Span(unsigned int N);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::iterator from, std::vector<int>::iterator to);
};

class SpanClassAlreadyFullException : public std::exception {
	const char * what() const throw();
};

class NotEnoughDataException : public std::exception {
	const char * what() const throw();
};

#endif
