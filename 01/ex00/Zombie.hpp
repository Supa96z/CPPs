/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:10:41 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 03:38:17 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
    
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
    
    private:
    
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif