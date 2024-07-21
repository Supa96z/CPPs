#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <cmath>
# include <limits>

class ScalarConverter
{
    protected:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &s);
        ScalarConverter &operator=(const ScalarConverter &s);
        ~ScalarConverter();

    public:
        static void convert(std::string);
};


#endif