/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:11:29 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:12:13 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default") , count(0) {
	std::cout << "\e[0;33mDefault Constructor of Character called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(std::string const & name) : name(name) , count(0) {
	std::cout << "\e[0;33mConstructor of Character called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

Character::Character(const Character &copy) {
	std::cout << "\e[0;33mCopy Constructor of Character called\e[0m" << std::endl;
	*this = copy;
}

Character::~Character() {
	std::cout << "\e[0;31mDestructor of Character called\e[0m" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
}

Character & Character::operator=(const Character &assign) {
	std::cout << "\e[0;33mAssignation operator of Character called\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->name = assign.getName();
	this->count = assign.count;
	for (int i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
	for (int i = 0; i < assign.count; i++) {
		this->equip(assign.materias[i]->clone());
	}
	return *this;
}

std::string const & Character::getName() const { return this->name; }

void Character::equip(AMateria *m) {
	if (this->count < 4) {
		this->materias[this->count] = m;
		this->count++;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->count) {
		this->materias[idx] = NULL;
	}
	for (int i = idx; i < this->count - 1; i++) {
		this->materias[i] = this->materias[i + 1];
	}
	this->materias[this->count - 1] = NULL;
	this->count--;
}

void Character::use(int idx, ICharacter& target) {
	if (this->materias[idx] && idx >= 0 && idx < this->count) {
		this->materias[idx]->use(target);
	}
}