/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:07:20 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 21:13:06 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    public:

    Weapon(std::string type);
    ~Weapon();
    
    std::string getType();
    void    setType(std::string newtype);

    private:

    std::string type;
};

#endif