/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:19:06 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:25:00 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap suuu;

	suuu.attack("Lucas");
	suuu.beRepaired(10);
	suuu.takeDamage(9);
	suuu.guardGate();
	return 0; 
}