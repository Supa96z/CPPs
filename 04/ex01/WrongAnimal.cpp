/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:46:10 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:46:46 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong animal") { std::cout << "\e[0;33mDefault Constructor of Wrong Animal called\e[0m" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "\e[0;33mCopy Constructor of Wrong Animal called\e[0m" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() { std::cout << "\e[0;31mDestructor of Wrong Animal called\e[0m" << std::endl; }

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign) {
	if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void WrongAnimal::makeSound( void ) const { std::cout << "Animal makes a sound !" << std::endl; }

std::string	WrongAnimal::getType( void ) const { return this->type; }