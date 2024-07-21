/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:11:07 by abataill          #+#    #+#             */
/*   Updated: 2024/02/07 20:11:57 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{

	private:
    
	int					_value;
	static const int	_fractionalBits = 8;


	public:
	
    Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
    ~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

};

#endif