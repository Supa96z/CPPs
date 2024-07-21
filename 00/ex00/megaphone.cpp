/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:09:55 by abataill          #+#    #+#             */
/*   Updated: 2023/12/10 07:22:59 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "*LOUD AND UNBEARABLE FEEDBACK NOISE*" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i){
        std::string InputString = argv[i];
        std::string CapitalizedString;
        for (int j = 0; j < InputString.length(); j++){
            CapitalizedString += std::toupper(InputString[j]);
        }
        std::cout << CapitalizedString;
    }
    std::cout << std::endl;
}
