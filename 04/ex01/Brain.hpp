/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:58:15 by abataill          #+#    #+#             */
/*   Updated: 2024/02/08 01:59:32 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain const & operator=(Brain const &assign);

	private:
		std::string *ideas[100];
};

#endif