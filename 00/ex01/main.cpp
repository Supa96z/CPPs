/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:21:04 by abataill          #+#    #+#             */
/*   Updated: 2023/12/15 23:26:21 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

int main(void){
    PhoneBook ThePhoneBook;
    std::string input;
    std::cout << "Hello :)" << std::endl;
    for (;;){
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD")
            ThePhoneBook.add();
        if (input == "SEARCH")
            ThePhoneBook.search();
        if (input == "EXIT")
            break;
    }
}