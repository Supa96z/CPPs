#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <vector>
# include <string>
# include <iostream>
# include <sstream>

class PmergeMe {
    private:
        std::vector<std::pair<int, int>> _data1;
        std::vector<int> _small1;
        std::vector<int> _big1;
        std::deque<std::pair<int, int>> _data2;
        std::deque<int> _small2;
        std::deque<int> _big2;
        int _last;
        void recursiveSort(std::vector<int> &toSort);
        void merge(std::vector<int> &left, std::vector<int> &right);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void parseSequence(int argc, char **argv);
        void sortWithVec();
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
