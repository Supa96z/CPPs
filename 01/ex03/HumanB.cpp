/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:39:34 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:31:31 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
}

HumanB::~HumanB(){}

void HumanB::attack(void){
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}