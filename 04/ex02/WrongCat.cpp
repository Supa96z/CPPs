/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:47:15 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:48:27 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "\e[0;33mDefault Constructor of Wrong Cat called\e[0m" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor of Wrong Cat called\e[0m" << std::endl;
}


WrongCat::~WrongCat() { std::cout << "\e[0;31mDestructor of Wrong Cat called\e[0m" << std::endl; }


WrongCat & WrongCat::operator=(const WrongCat &assign) {
	if (&assign == this)
		return *this;
	this->type = assign.getType();
	return *this;
}

void WrongCat::makeSound( void ) const { std::cout << "Wrong Meeeowwww !" << std::endl; }