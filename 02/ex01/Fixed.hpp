/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:18:02 by abataill          #+#    #+#             */
/*   Updated: 2024/02/07 20:18:37 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

	private:
		
    int					_value;
	static const int	_fractionalBits = 8;


	public:

	Fixed();
	Fixed(const int value);

	Fixed(const float value);
	Fixed(const Fixed &copy);

	~Fixed();
	
	Fixed &operator=(const Fixed &copy);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream&   operator<< (std::ostream &os, Fixed const &f);


#endif