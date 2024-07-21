/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:13:32 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:14:02 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "\e[0;33mDefault Constructor of Cure called\e[0m" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &copy) {
	std::cout << "\e[0;33mCopy Constructor of Cure called\e[0m" << std::endl;
	*this = copy;
}

Cure::~Cure() { std::cout << "\e[0;31mDestructor of Cure called\e[0m" << std::endl; }

Cure & Cure::operator=(const Cure &assign) {
	std::cout << "\e[0;33mAssignation operator of Cure called\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria * Cure::clone() const { return new Cure(); }