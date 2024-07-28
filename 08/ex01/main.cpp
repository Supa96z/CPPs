#include "Span.hpp"

int main(){
	try{
	Span sp = Span(3);

	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(1);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
	Span sp = Span(9999);
	std::vector<int> range;
	for (std::size_t i = 0; i < 10000; i++)
		range.push_back(i);
	sp.addRange(range.begin(), range.end());
	}
	catch (std::exception &e){
		std::cout << e.what() <<std::endl;
	}
}
