#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <vector>
# include <string>
# include <iostream>
# include <sstream>
# include <chrono>
# include <iomanip>

class PmergeMe {
    private:
        std::vector<std::pair<int, int>> _data1;
        std::deque<std::pair<int, int>> _data2;
        int _last;
        int _info;

        void parseSequence(int argc, char **argv);
        void sortWithVec();
        void sortWithDeq();
        template<typename T>
        void recursiveSort(T &toSort);
        template<typename T>
        void merge(T &left, T &right, T &merged);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void pMergeMe(int argc, char **argv, int i);
        int _size;
};

class ContainsNonDigitException : public std::exception {
    const char * what() const throw();
};

class TooManySpacesException : public std::exception {
    const char * what() const throw();
};

class OutOfBoundsException : public std::exception {
    const char * what() const throw();
};

class BadInputException : public std::exception {
    const char * what() const throw();
};

#endif
