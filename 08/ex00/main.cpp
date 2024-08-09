#include "easyfind.hpp"

int main(){
	try{
	int n = 8;
	std::vector<int> v;
	for (int i = 1; i <= 30; i *= 2)
		v.push_back(i);
	std::cout << "List goes like this: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	easyfind(v, n);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try{
	int n = 7;
	std::deque<int> flst;
	for (int i = 1; i <= 30; i *= 2)
		flst.push_front(i);
	std::cout << "List goes like this: ";
	for (std::deque<int>::iterator it = flst.begin(); it != flst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	easyfind(flst, n);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
