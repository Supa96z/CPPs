/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:10:38 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 04:08:39 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(void){
    std::cout << this->name;
    std::cout << ": Dropped down dead after a dope headshot." << std::endl;
}

void    Zombie::announce(void){
    std::cout << this->name;
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}