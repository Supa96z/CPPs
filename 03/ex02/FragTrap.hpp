/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:30:07 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:30:08 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
    FragTrap();
    FragTrap( std::string name );
    FragTrap(FragTrap const &s);
    ~FragTrap();
    FragTrap &operator=(const FragTrap &copy);
    void highFivesGuys(void);
};

#endif