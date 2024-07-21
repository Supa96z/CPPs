/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:17:01 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:17:11 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();
		
		MateriaSource & operator=(const MateriaSource &assign);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

private:
		AMateria *materia[4];
		int count;
};

#endif