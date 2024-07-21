/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:37:43 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:43:53 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("animal") { std::cout << "\e[0;33mDefault Constructor of Animal called\e[0m" << std::endl; }

Animal::Animal(const Animal &copy) {
	std::cout << "\e[0;33mCopy Constructor of Animal called\e[0m" << std::endl;
	*this = copy;
}

Animal::~Animal() { std::cout << "\e[0;31mDestructor of Animal called\e[0m" << std::endl; }

Animal const & Animal::operator=(Animal const &assign) {
		if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void Animal::makeSound( void ) const { std::cout << "Animal makes a sound !" << std::endl; }

std::string	Animal::getType( void ) const { return this->type; }