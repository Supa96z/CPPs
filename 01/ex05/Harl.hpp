/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:02:15 by abataill          #+#    #+#             */
/*   Updated: 2024/01/20 03:09:42 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    private:
    
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    
    public:
    
    Harl();
    ~Harl();
    
    void complain( std::string level );
};

#endif