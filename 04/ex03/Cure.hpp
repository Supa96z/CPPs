/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:14:24 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:14:35 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria{

public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		
		Cure & operator=(const Cure &assign);

		void use(ICharacter& target);
		AMateria * clone() const;
};

#endif