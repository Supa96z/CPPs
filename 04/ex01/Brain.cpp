/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:58:13 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:59:08 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() { std::cout << "\e[0;33mDefault Constructor of Brain called\e[0m" << std::endl; }

Brain::Brain(const Brain &copy) {
	std::cout << "\e[0;33mCopy Constructor of Brain called\e[0m" << std::endl;
	*this = copy;
}

Brain::~Brain() { std::cout << "\e[0;31mDestructor of Brain called\e[0m" << std::endl; }

Brain const & Brain::operator=(Brain const &assign) {
	if (&assign == this)
		return *this;
	for (int i = 0; i < 100; i++)
	 	this->ideas[i] = assign.ideas[i];
	return *this;
}