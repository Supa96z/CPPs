/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:41:15 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 02:02:59 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		
		Animal const & operator=(Animal const &assign);
		
		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;


	protected:
		std::string type;
};

#endif