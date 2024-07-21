/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:14:47 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:15:21 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	std::cout << "\e[0;33mDefault Constructor of Ice called\e[0m" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &copy) {
	std::cout << "\e[0;33mCopy Constructor of Ice called\e[0m" << std::endl;
	*this = copy;
}

Ice::~Ice() { std::cout << "\e[0;31mDestructor of Ice called\e[0m" << std::endl; }

Ice & Ice::operator=(const Ice &assign) {
	std::cout << "\e[0;33mAssignation operator of Ice called\e[0m" << std::endl;
	if (&assign == this) { return *this; }
	this->type = assign.type;
	return *this;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria * Ice::clone() const { return new Ice(); }