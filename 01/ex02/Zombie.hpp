/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:10:41 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 04:27:53 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
    
    Zombie();
    ~Zombie();
    
    void announce(void);
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif