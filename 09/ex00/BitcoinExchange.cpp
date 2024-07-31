#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange &other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

void BitcoinExchange::exchange(std::fstream &data, std::fstream &input) {
    this->extractData(data);
    this->interpretInput(input);
}

void BitcoinExchange::interpretInput(std::fstream &input) {
    std::string line, tmp1, tmp2, trash, printDate;
    std::getline(input, line);
    std::istringstream iss(line);
    if (!line.size() || line.compare("date | value"))
        throw InvalidInputFormatException();
    while (std::getline(input, line)){
        if (this->checkFormat(line, "****-**-** | #") == false){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        iss.str(line);
        std::getline(iss, tmp1, ' ');
        std::getline(iss, trash, ' ');
        std::getline(iss, tmp2, '\n');
        iss.clear();
        printDate = tmp1;
        tmp1.erase(std::remove(tmp1.begin(), tmp1.end(), '-'), tmp1.end());
        int date;
        try {
            date = std::stoi(tmp1);
        }
        catch (std::exception &e) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        float value;
        try {
            value = std::stof(tmp2);
        }
        catch (std::exception &e) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (checkDate(date) == false){
            std::cout << "Error: date incompatible." << std::endl;
            continue;
        }
        if (value < 0){
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value >= 2147483648){
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<int, float>::const_iterator it = this->_data.find(date);
        if (it != this->_data.end()){
            std::cout << printDate << " => " << tmp2 << " = " << this->_data[date] * value << std::endl;
        }
        else {
            std::map<int, float>::const_iterator lower = this->_data.lower_bound(date);
            if (lower == this->_data.begin())
                continue;
            --lower;
            std::cout << printDate << " => " << tmp2 << " = " << this->_data[lower->first] * value << std::endl;
        }
    }
}

bool BitcoinExchange::checkFormat(std::string line, std::string format) {
    std::string::iterator it1 = line.begin();
    std::string::iterator it2 = format.begin();
    std::string toFind = "0123456789.";
    for (; it1 != line.end() && it2 != format.end(); it1++, it2++){
        if (*it2 == '*' && !std::isdigit(*it1)){
            return false;
        }
        else if (*it2 == '#'){
            for (;it1 != line.end(); it1++){
                if (*it1 == '-')
                    continue;
                if (toFind.find(*it1) == std::string::npos){
                    return false;
                }
            }
        }
        else if (*it2 != *it1 && *it2 != '*'){
            return false;
        }
    }
    if (it2 != format.end())
        return false;
    return true;
}

bool BitcoinExchange::checkDate(int date) {
    int year = date / 10000;
    int md = date % 10000;
    int month = md / 100;
    int day = date % 100;

    if (year < 2009 || year > 2024)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}

void BitcoinExchange::extractData(std::fstream &data) {
    std::string line, tmp1, tmp2;
    std::getline(data, line);
    std::istringstream iss(line);
    if (!line.size() || line.compare("date,exchange_rate"))
        throw InvalidFormatException();
    while (std::getline(data, line)){
        if (this->checkFormat(line, "****-**-**,#") == false)
            throw InvalidFormatException();
        iss.str(line);
        std::getline(iss, tmp1, ',');
        std::getline(iss, tmp2, '\n');
        iss.clear();
        tmp1.erase(std::remove(tmp1.begin(), tmp1.end(), '-'), tmp1.end());
        int date;
        try {
            date = std::stoi(tmp1);
        }
        catch (std::exception &e) {
            throw OutOfBoundsException();
        }
        float value;
        try {
            value = std::stof(tmp2);
        }
        catch (std::exception &e) {
            throw OutOfBoundsException();
        }
        if (value < 0)
            throw InvalidPriceException();
        if (checkDate(date) == false)
            throw InvalidDateException();
        this->_data[date] = value;
    }
}

const char *InvalidDateException::what() const throw() {
    return "Error: data.csv: invalid date.";
}

const char *InvalidFormatException::what() const throw() {
    return "Error: data.csv: invalid format.";
}

const char *InvalidPriceException::what() const throw() {
    return "Error: data.csv: invalid Bitcoin price.";
}

const char *InvalidInputFormatException::what() const throw() {
    return "Error: input.txt: invalid format.";
}

const char *OutOfBoundsException::what() const throw() {
    return "Error: a number was out of bounds.";
}
