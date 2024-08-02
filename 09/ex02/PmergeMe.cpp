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

void PmergeMe::sortWithVec() {
    std::vector<std::pair<int, int>>::iterator it = this->_data1.begin();
    for (; it != this->_data1.end(); it++){
        if (it->first > it->second){
            int tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
    }
    it = this->_data1.begin();
    for (; it != this->_data1.end(); it++){
        this->_small1.push_back(it->first);
        this->_big1.push_back(it->second);
    }
    if (this->_last)
        this->_big1.push_back(this->_last);
    this->_data1.clear();
    recursiveSort(this->_big1);
    /*for (std::vector<int>::iterator issou = this->_big1.begin(); issou != this->_big1.end(); issou++)
        std::cout << *issou << std::endl;*/
    std::cout << this->_big1.size() << std::endl;
}

void PmergeMe::recursiveSort(std::vector<int> &toSort) {
    if (toSort.size() <= 1)
        return;
    int mid = toSort.size() / 2;
    std::vector<int> left(toSort.begin(), toSort.begin() + mid);
    std::vector<int> right(toSort.begin() + mid, toSort.end());
    recursiveSort(left);
    recursiveSort(right);
    merge(left, right);
}

void PmergeMe::merge(std::vector<int> &left, std::vector<int> &right) {
    std::vector<int>::iterator it1 = left.begin();
    std::vector<int>::iterator it2 = right.begin();
    while (it2++ != right.end())
        left.insert(std::lower_bound(left.begin(), left.end(), *it2), *it2);
    if (left.size() == this->_big1.size()){
        this->_big1.clear();
        for (; it1 != left.end(); it1++)
            this->_big1.push_back(*it1);
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
            if (!std::isdigit(*it1))
                throw TooManySpacesException();
            if (!hasFirst){
                try { nb1 = std::stoi(n); } catch (std::exception &e) { throw OutOfBoundsException(); }
                hasFirst = true;
            }
            else {
                try { nb2 = std::stoi(n); } catch (std::exception &e) { throw OutOfBoundsException(); }
                hasFirst = false;
                hasBoth = true;
            }
            if (hasBoth){
                this->_data1.emplace_back(nb1, nb2);
                this->_data2.emplace_back(nb1, nb2);
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
            for (; it != seq.end(); it++){
                if (!std::isdigit(*it))
                    throw ContainsNonDigitException();
            }
            if (!hasFirst){
                try { nb1 = std::stoi(seq); } catch (std::exception &e) { throw OutOfBoundsException(); }
                hasFirst = true;
            }
            else {
                try { nb2 = std::stoi(seq); } catch (std::exception &e) { throw OutOfBoundsException(); }
                hasFirst = false;
                hasBoth = true;
            }
            if (hasBoth){
                this->_data1.emplace_back(nb1, nb2);
                this->_data2.emplace_back(nb1, nb2);
                hasBoth = false;
            }
        }
        if (hasFirst && !hasBoth)
            this->_last = nb1;
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
