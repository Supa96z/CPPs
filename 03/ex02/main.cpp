/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:31:10 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:31:35 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
	FragTrap suuu;

	suuu.attack("Lucas");
	suuu.beRepaired(10);
	suuu.takeDamage(9);
	suuu.highFivesGuys();
	return 0; 
}