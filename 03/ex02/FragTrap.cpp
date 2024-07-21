/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:29:56 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:32:45 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damageAttack = 30;
	std::cout << "FragTrap Default contrustor called." << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damageAttack = 30;
	std::cout << "FragTrap Constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const  &s) {
	std::cout << "Copy constructor called." << std::endl;
	this->damageAttack = s.damageAttack;
	this->energyPoints = s.energyPoints;
	this->hitPoints = s.hitPoints;
	this->name = s.name;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destrustor called." << std::endl; }

FragTrap & FragTrap::operator=(FragTrap const &copy) {
	std::cout << "Assignation operator called." << std::endl;
	this->damageAttack = copy.damageAttack;
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->name = copy.name;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Guys ! High five !" << std::endl;
}