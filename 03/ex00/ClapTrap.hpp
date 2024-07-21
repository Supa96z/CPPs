/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:15:08 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:15:09 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {

private:
        std::string name;
        int         hitPoints;
        int         energyPoints;
        int         damageAttack;

public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap const &s);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif