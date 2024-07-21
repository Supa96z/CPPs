/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:34:55 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:33:45 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
    
    HumanB(std::string name);
    ~HumanB();

    void attack(void);
    void setWeapon(Weapon &weapon);

    private:
    
    Weapon *weapon;
    std::string name;
};

#endif