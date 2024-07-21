/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:10:46 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:12:38 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("AMateria") { std::cout << "\e[0;33mDefault Constructor of AMateria called\e[0m" << std::endl; }

AMateria::AMateria(std::string const & type) : type(type) { std::cout << "\e[0;33mConstructor of AMateria called\e[0m" << std::endl; }

AMateria::AMateria(const AMateria &copy) {
	std::cout << "\e[0;33mCopy Constructor of AMateria called\e[0m" << std::endl;
	*this = copy;
}

AMateria::~AMateria() { std::cout << "\e[0;31mDestructor of AMateria called\e[0m" << std::endl; }

AMateria & AMateria::operator=(const AMateria &assign) {
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

std::string const & AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter& target) {
	std::cout << " * AMateria " << target.getName() << " *" << std::endl;
}