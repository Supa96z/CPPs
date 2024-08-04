#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "Error: no arguments." << std::endl;
        return 0;
    }
    argv++;

    PmergeMe fj;

    auto t1 = std::chrono::high_resolution_clock::now();

    try { fj.pMergeMe(argc, argv, 1); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    auto t2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::micro> time = t2 - t1;

    std::cout << "Time to process a range of " << fj._size << " elements with std::vector : " << std::fixed << std::setprecision(5) << time.count() << " µs" << std::endl;


    t1 = std::chrono::high_resolution_clock::now();

    try { fj.pMergeMe(argc, argv, 0); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    t2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::micro> time2 = t2 - t1;

    std::cout << "Time to process a range of " << fj._size << " elements with std::deque : " << std::fixed << std::setprecision(5) << time2.count() << " µs" << std::endl;
}
