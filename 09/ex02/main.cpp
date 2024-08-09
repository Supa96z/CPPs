#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "Error: no arguments." << std::endl;
        return 0;
    }
    argv++;

    PmergeMe fj;

    clock_t start = clock();
    try { fj.pMergeMe(argc, argv, 1); } catch (std::exception &e) { std::cerr << e.what() << std::endl; exit(1); }

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << fj._size << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_taken << " µs" << std::endl;


    start = clock();

    try { fj.pMergeMe(argc, argv, 0); } catch (std::exception &e) { std::cerr << e.what() << std::endl; exit(1); }

    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << fj._size << " elements with std::deque : " << std::fixed << std::setprecision(5) << time_taken << " µs" << std::endl;
}
