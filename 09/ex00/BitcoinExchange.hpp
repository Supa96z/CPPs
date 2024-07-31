#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <iostream>
# include <algorithm>

class BitcoinExchange {

    private:
        std::map<int, float> _data;
        void extractData(std::fstream &data);
        void interpretInput(std::fstream &input);
        bool checkFormat(std::string line, std::string format);
        bool checkDate(int date);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void exchange(std::fstream &data, std::fstream &input);
};

class InvalidDateException : public std::exception {
    const char * what() const throw();
};

class InvalidFormatException : public std::exception {
    const char * what() const throw();
};

class InvalidPriceException : public std::exception {
    const char * what() const throw();
};

class InvalidInputFormatException : public std::exception {
    const char * what() const throw();
};

class OutOfBoundsException : public std::exception {
    const char * what() const throw();
};

#endif
