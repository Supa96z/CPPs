/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 01:10:29 by abataill          #+#    #+#             */
/*   Updated: 2024/01/10 04:59:54 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <string>
#include <iostream>

int main(){
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << std::addressof(string) << std::endl;
    std::cout << std::addressof(stringPTR) << std::endl;
    std::cout << std::addressof(stringREF) << std::endl;

    std::cout << string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}