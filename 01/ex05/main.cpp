/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:22:35 by abataill          #+#    #+#             */
/*   Updated: 2024/01/20 03:25:25 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
    Harl harl;
    std::cout << "Cashier: Alright Sir, your order is ready. Did you really order extra bacon with this GINORMOUS burger??" << std::endl;
    harl.complain("debug");
    std::cout << "Cashier: You're the boss. Its gonna be 2 pounds extra though..." << std::endl;
    harl.complain("info");
    std::cout << "Cashier: I'm not making the rules, nor the burger, so I have to charge you for it." << std::endl;
    harl.complain("warning");
    std::cout << "Cashier: Hey you coming since before I started working here has nothing to do with it! As I said, I'm not the one making the rules." << std::endl;
    harl.complain("error");
    std::cout << "Cashier: Well too bad, he's taking a shit right now. But I'll tell him you said hi." << std::endl;
    harl.complain("wrong one");
}