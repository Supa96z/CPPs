#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &s) { (void)s; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &s) { (void)s; return (*this); }

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str)
{
    /* Takes care of special literals*/
    int i = 0;
    std::string s[5]={"nan", "+inf", "-inf", "+inff", "-inff"};

    while (i < 5 && s[i].compare(str))
        i++;
    if (i < 5)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        if (i > 2){
        std::cout << "float : " << s[i - 2] << "f" << std::endl;
        std::cout << "double : " << s[i - 2] << std::endl;
        } else {
        std::cout << "float : " << s[i] << "f" << std::endl;
        std::cout << "double : " << s[i] << std::endl;
        }
        exit(0);
    }

    /* Check for single char */

    bool isChar = false;
    std::string::iterator ch = str.begin();
    if (str.length() == 1 && (*ch > 32 && *ch < 127)){
        std::cout << "char : " << *ch << std::endl;
        int c;
        float h;
        double a;
        c = static_cast<int>(*ch);
        h = static_cast<float>(*ch);
        a = static_cast<double>(*ch);
        std::cout << "int : " << c << std::endl;
        std::cout << "float : " << h << ".0f" << std::endl;
        std::cout << "double : " << a << ".0" << std::endl;
        isChar = true;
    }

    /* Check format for the right conversion and cast */
    bool db = false;
    bool fl = false;
    bool it = false;
    i = 0;

    i = str.find_first_not_of("0123456789");
    if (i == -1)
        it = true;
    else
    {
        if (i == 0 && (str[i] != '+' && str[i] != '-') && isChar == false){
            std::cout << "Wrong format" << std::endl;
            exit(1);
        }
        else
        {
            if (i == 0 && (str[i] == '+' || str[i] == '-'))
            {
                i = str.find_first_not_of("0123456789", ++i);
                if (i == -1)
                    it = true;
            }
            if (i != -1 && str[i] == '.')
            {
                i = str.find_first_not_of("0123456789", ++i);
                if (i == -1)
                    db = true;
                if (i != -1 && str[i] == 'f')
                {
                    i = str.find_first_not_of("0123456789", ++i);
                    if (i == -1){
                        db = false;
                        fl = true;
                    }
                    if (i != -1)
                    {
                        std::cout << "Wrong format" << std::endl;
                        exit(1);
                    }
                }
                else if (i != -1)
                {
                    std::cout << "Wrong format" << std::endl;
                    exit(1);
                }
            }
            else if (i != -1 && isChar == false)
            {
                std::cout << "Wrong format" << std::endl;
            std::cout << "here" << std::endl;
                exit(1);
            }
        }
    }

    /* Get ammount of digits to get real size for setprecision */

    int size = 0;
    std::string::iterator st = str.begin();
    if (*st == '+' || *st == '-')
        ++st;
    for (; *st == '0' && st != str.end(); st++);
    for (; std::isdigit(*st) && st != str.end(); st++)
        size++;
    if (*st == '.'){
        ++st;
        for (; std::isdigit(*st) && st != str.end(); st++)
            size++;
    }
    int fsize = size;
    int dsize = size;
    if (size > 7)
        fsize = 7;
    if (size > 16)
        dsize = 16;

    /* Convert, cast and print */
    i = 0;
    double d;
    float f;
    char c;
    bool displayableChar = false;
    bool overflowF = false;
    bool overflowI = false;
    std::stringstream ss(str);
    if (db == true) // From double literal in string
    {
        ss >> d;
        if (ss.fail()){
            std::cout << "Exception: out of range for a literal type double." << std::endl;
            exit(1);
        }
        if (d < (-std::numeric_limits<float>::max()) || d > std::numeric_limits<float>::max())
            overflowF = true;
        else{
            f = static_cast<float>(d);
            if (d < (-std::numeric_limits<int>::max() - 1) || d > std::numeric_limits<int>::max())
                overflowI = true;
            else
                i = static_cast<int>(d);
        }
        if (i > 32 && i < 127){
            displayableChar = true;
            c = static_cast<char>(i);
        }
        if (displayableChar == false)
            std::cout << "char: undisplayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        if (overflowF == true){
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: overflow" << std::endl;
        }
        else{
            if (overflowI == true)
                std::cout << "int: overflow" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
            if (std::fmod(f, 1.0) == 0 && f > -1000000 && f < 1000000)
                std::cout << "float: " << std::setprecision(fsize) << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        if (std::fmod(d, 1.0) == 0 && d > -1000000 && d < 1000000)
            std::cout << "double: " << std::setprecision(dsize) << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    else if (fl == true) // From float literal in string
    {
        ss >> f;
        if (ss.fail()){
            std::cerr << "Exception: out of range of a literal type float." << std::endl;
            exit(1);
        }
        if (f < (-std::numeric_limits<int>::max() - 1) || f > std::numeric_limits<int>::max())
            overflowI = true;
        else
            i = static_cast<int>(f);
        d = static_cast<double>(f);
        if (i > 32 && i < 127){
            displayableChar = true;
            c = static_cast<char>(i);
        }
        if (displayableChar == false)
            std::cout << "char: undisplayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        if (overflowF == true)
        {
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: overflow" << std::endl;
        }
        else
        {
            if (overflowI == true)
                std::cout << "int: overflow" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
            if (std::fmod(f, 1.0) == 0 && f > -1000000 && f < 1000000)
                std::cout << "float: " << std::setprecision(fsize) << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        if (std::fmod(d, 1.0) == 0 && d > -1000000 && d < 1000000)
            std::cout << "double: " << std::setprecision(dsize) << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    else if (it == true) // From int in string
    {
        ss >> i;
        if (ss.fail())
        {
            std::cerr << "Exception: out of range of a literal type int." << std::endl;
            exit(1);
        }
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        if (i > 32 && i < 127){
            displayableChar = true;
            c = static_cast<char>(i);
        }
        if (displayableChar == false)
            std::cout << "char: undisplayable" << std::endl;
        else
            std::cout << "char: " << c << std::endl;
        if (overflowF == true)
        {
            std::cout << "int: overflow" << std::endl;
            std::cout << "float: overflow" << std::endl;
        }
        else
        {
            if (overflowI == true)
                std::cout << "int: overflow" << std::endl;
            else
                std::cout << "int: " << i << std::endl;
            if (std::fmod(f, 1.0) == 0 && f > -1000000 && f < 1000000)
                std::cout << "float: " << std::setprecision(fsize) << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;
        }
        if (std::fmod(d, 1.0) == 0 && d > -1000000 && d < 1000000)
            std::cout << "double: " << std::setprecision(dsize) << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
}
