/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:57:35 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 04:24:14 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    Zombie *zombie = new Zombie[N];
    for (int i=0; i < N; ++i){
        zombie[i].name = name;
    }
    return zombie;
}