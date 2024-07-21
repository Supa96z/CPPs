/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:15:29 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:15:41 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria{

public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		
		Ice & operator=(const Ice &assign);

		void use(ICharacter& target);
		AMateria * clone() const;
};

#endif