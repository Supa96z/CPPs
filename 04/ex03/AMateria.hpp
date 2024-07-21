/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:11:05 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:11:17 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
		std::string type;

public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);

		virtual ~AMateria();

		AMateria & operator=(const AMateria &assign);

		std::string const & getType() const;
 		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif