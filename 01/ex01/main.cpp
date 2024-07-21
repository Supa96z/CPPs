/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:10:29 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 04:37:48 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie *horde = zombieHorde(12, "Foo");
    for (int i = 0; i < 12; ++i){
        horde[i].announce();
    }
    delete [] horde;
}