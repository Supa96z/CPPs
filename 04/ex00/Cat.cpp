/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:41:40 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:43:07 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "\e[0;33mDefault Constructor of Cat called\e[0m" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor of Cat called\e[0m" << std::endl;
}

Cat::~Cat() { std::cout << "\e[0;31mDestructor of Cat called\e[0m" << std::endl; }

Cat & Cat::operator=(const Cat &assign) {
	if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "Meeeowwww !" << std::endl; }