/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:12:50 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:13:24 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter{

public:
		Character();
		Character(std::string const & name);
		Character(const Character &copy);
		~Character();

		Character & operator=(const Character &assign);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

private:

		std::string		name;
		int				count;
		AMateria		*materias[4];

};

#endif