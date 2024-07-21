/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:39:36 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:21:06 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack(void){
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}