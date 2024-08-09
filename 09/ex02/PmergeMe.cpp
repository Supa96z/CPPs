#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other){
        this->_data1 = other._data1;
        this->_data2 = other._data2;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::pMergeMe(int argc, char **argv, int i) {
    this->_info = i;
    parseSequence(argc, argv);
    if (i)
        sortWithVec();
    else
        sortWithDeq();
}

void PmergeMe::sortWithVec() {
    for (std::vector<std::pair<int, int> >::iterator it = this->_data1.begin(); it != this->_data1.end(); it++){
        if (it->first > it->second){
            int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }
    std::vector<int> small;
    std::vector<int> big;
    for (std::vector<std::pair<int, int> >::iterator it = this->_data1.begin(); it != this->_data1.end(); it++){
        small.push_back(it->first);
        big.push_back(it->second);
    }
    if (this->_last)
        big.push_back(this->_last);
    this->_data1.clear();
    recursiveSort(big);
    for (std::vector<int>::iterator it = small.begin(); it != small.end(); it++)
        big.insert(std::lower_bound(big.begin(), big.end(), *it), *it);
    if (this->_info == 1){
        std::cout << "After:  ";
        for (std::vector<int>::iterator it = big.begin(); it != big.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
}

void PmergeMe::sortWithDeq() {
    for (std::deque<std::pair<int, int> >::iterator it = this->_data2.begin(); it != this->_data2.end(); it++){
        if (it->first > it->second){
            int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }
    std::deque<int> small;
    std::deque<int> big;
    for (std::deque<std::pair<int, int> >::iterator it = this->_data2.begin(); it != this->_data2.end(); it++){
        small.push_back(it->first);
        big.push_back(it->second);
    }
    if (this->_last)
        big.push_back(this->_last);
    this->_data2.clear();
    recursiveSort(big);
    for (std::deque<int>::iterator it = small.begin(); it != small.end(); it++)
        big.insert(std::lower_bound(big.begin(), big.end(), *it), *it);
}

template<typename T>
void PmergeMe::recursiveSort(T &toSort) {
    if (toSort.size() <= 1)
        return;
    int mid = toSort.size() / 2;
    T left(toSort.begin(), toSort.begin() + mid);
    T right(toSort.begin() + mid, toSort.end());
    recursiveSort(left);
    recursiveSort(right);
    T merged;
    merge(left, right, merged);
    toSort.clear();
    toSort.insert(toSort.end(), merged.begin(), merged.end());
}

template<typename T>
void PmergeMe::merge(T &left, T &right, T &merged) {
    typename T::iterator it1 = left.begin();
    typename T::iterator it2 = right.begin();
    while (it1 != left.end() && it2 != right.end()){
        if (*it1 <= *it2){
            merged.push_back(*it1);
            ++it1;
        }
        else {
            merged.push_back(*it2);
            ++it2;
        }
    }
    while (it1 != left.end()){
        merged.push_back(*it1);
        ++it1;
    }
    while (it2 != right.end()){
        merged.push_back(*it2);
        ++it2;
    }
}


void PmergeMe::parseSequence(int argc, char **argv) {
    this->_last = 0;
    if (argc == 2){
        std::string seq = argv[0];
        std::string::iterator it = seq.begin();
        for (; it != seq.end(); it++){
            if (*it != ' ' && !std::isdigit(*it))
                throw ContainsNonDigitException();
        }
        std::string n;
        int nb1;
        int nb2;
        bool hasFirst = false;
        bool hasBoth = false;
        std::istringstream iss(seq);
        while (std::getline(iss, n, ' ')){
            std::string::iterator it1 = n.begin();
            std::stringstream ss(n);
            if (!std::isdigit(*it1))
                throw TooManySpacesException();
            if (!hasFirst){
                ss >> nb1;
                if (ss.fail())
                    throw OutOfBoundsException();
                hasFirst = true;
            }
            else {
                ss >> nb2;
                if (ss.fail())
                    throw OutOfBoundsException();
                hasFirst = false;
                hasBoth = true;
            }
            if (hasBoth){
                this->_data1.push_back(std::make_pair(nb1, nb2));
                this->_data2.push_back(std::make_pair(nb1, nb2));
                hasBoth = false;
            }
        }
        if (hasFirst && !hasBoth)
            this->_last = nb1;
    }
    else{
        int nb1;
        int nb2;
        bool hasFirst = false;
        bool hasBoth = false;
        std::string seq;
        for (int i = 0; argv[i]; i++){
            seq = argv[i];
            std::string::iterator it = seq.begin();
            std::stringstream ss(seq);
            for (; it != seq.end(); it++){
                if (!std::isdigit(*it))
                    throw ContainsNonDigitException();
            }
            if (!hasFirst){
                ss >> nb1;
                if (ss.fail())
                    throw OutOfBoundsException();
                hasFirst = true;
            }
            else {
                ss >> nb2;
                if (ss.fail())
                    throw OutOfBoundsException();
                hasFirst = false;
                hasBoth = true;
            }
            if (hasBoth){
                this->_data1.push_back(std::make_pair(nb1, nb2));
                this->_data2.push_back(std::make_pair(nb1, nb2));
                hasBoth = false;
            }
        }
        if (hasFirst && !hasBoth)
            this->_last = nb1;
    }
    this->_size = this->_data1.size() * 2;
    if (this->_last)
        this->_size += 1;
    if (this->_info == 1){
        std::vector<std::pair<int, int> >::iterator it = this->_data1.begin();
        std::cout << "Before: ";
        for (; it != this->_data1.end(); it++)
            std::cout << it->first << " " << it->second << " ";
        if (this->_last)
            std::cout << this->_last << " ";
        std::cout << std::endl;
    }
}

const char *BadInputException::what() const throw() {
    return "Error: bad sequence.";
}

const char *OutOfBoundsException::what() const throw() {
    return "Error: a number is too large.";
}

const char *TooManySpacesException::what() const throw() {
    return "Error: too many spaces between two numbers.";
}

const char *ContainsNonDigitException::what() const throw() {
    return "Error: characters passed as argument were non digit.";
}
