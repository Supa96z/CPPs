#include "MutantStack.hpp"

int main(){
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	
	std::cout << "Stack elements (normal iteration):" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        	std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Stack elements (reverse iteration):" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        	std::cout << *rit << " ";
    	}
	std::cout << std::endl;
	return 0;

}
