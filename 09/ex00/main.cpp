#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "Error: bad arguments!" << std::endl;
        return 0;
    }

    std::fstream input;
    input.open("./input.txt");
    if (!input){
        std::cerr << "Error: couldn't open the input file." << std::endl;
        return 0;
    }

    std::fstream data;
    data.open("./data.csv");
    if (!data){
        std::cerr << "Error: couldn't open the data file." << std::endl;
        return 0;
    }

    BitcoinExchange btc;
    
    try{
        btc.exchange(data, input);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}
