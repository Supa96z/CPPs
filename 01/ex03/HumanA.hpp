/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:33:52 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:29:26 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:

    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack(void);

    private:

    std::string name;
    Weapon &weapon;
};

#endif