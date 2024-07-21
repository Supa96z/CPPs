#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <class T, std::size_t N, class F>
void iter(T (&array)[N], F f)
{
    for (std::size_t i = 0; i < N; i++)
        f(array[i]);
}

#endif