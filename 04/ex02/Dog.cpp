/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:44:28 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:45:12 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "\e[0;33mDefault Constructor of Dog called\e[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor of Dog called\e[0m" << std::endl;
}


Dog::~Dog() { std::cout << "\e[0;31mDestructor of Dog called\e[0m" << std::endl; }


Dog & Dog::operator=(const Dog &assign) {
	if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "Wouuf Wouuf !" << std::endl; }