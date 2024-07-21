/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:26:59 by abataill          #+#    #+#             */
/*   Updated: 2024/01/20 03:24:29 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
    std::cout << "Harl entered the restaurant." << std::endl;
}

Harl::~Harl(){
    std::cout << "Harl left, shouting 'this isn't over'." << std::endl;
}

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level){
    
    void (Harl::*function[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    
    std::string levels[4] = { "debug", "info", "warning", "error" };
    
    for (int i = 0; i < 4; ++i){
        if (level == levels[i])
            (this->*function[i])();
    }
}