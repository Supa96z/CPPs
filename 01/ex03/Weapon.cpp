/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:12:13 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:13:13 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->type = type;
}

Weapon::~Weapon(){}

void Weapon::setType(std::string newtype){
    this->type = newtype;
}

std::string Weapon::getType(){
    return this->type;
}