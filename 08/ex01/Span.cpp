#include "Span.hpp"

Span::Span() : _data() {}

Span::Span(const Span& s) : _data(s._data) {}

Span &Span::operator=(const Span& s) { return *this; }

Span::~Span() {}

Span::Span(unsigned int N) : _data(), _sizeMax(N) { this->_data.reserve(N); }

void Span::addNumber(int n) {
	if (this->_data.size() >= this->_sizeMax)
		throw SpanClassAlreadyFullException();
	this->_data.push_back(n);
}

int Span::shortestSpan() {
	if (this->_data.size() < 2)
		throw NotEnoughDataException();
	std::vector<int> _sortedData = this->_data;
	std::sort(_sortedData.begin(), _sortedData.end());

	int span = 0;
	int shortest = std::numeric_limits<int>::max();
	for (std::size_t i = 1; i < _sortedData.size(); i++){
		span = _sortedData[i] - _sortedData[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan() {
	if (this->_data.size() < 2)
		throw NotEnoughDataException();

	int biggest = *std::max_element(this->_data.begin(), this->_data.end());
	int smallest = *std::min_element(this->_data.begin(), this->_data.end());

	int span = biggest - smallest;
	return span;
}

void Span::addRange(std::vector<int>::iterator from, std::vector<int>::iterator to) {
	if (static_cast<int>(to - from + this->_data.size()) > this->_sizeMax)
		throw SpanClassAlreadyFullException();
	this->_data.insert(this->_data.end(), from, to);
}

const char *SpanClassAlreadyFullException::what() const throw() {
	return ("Class Span already full.");
}

const char *NotEnoughDataException::what() const throw() {
	return ("Not enough data to calculate any span.");
}
