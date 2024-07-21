/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:45:38 by abataill          #+#    #+#             */
/*   Updated: 2023/12/15 22:43:33 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->i = 0;
}

PhoneBook::~PhoneBook() {};

void PhoneBook::add() {
    std::string FirstName;
	std::cout << "First Name : ";
	std::getline(std::cin, FirstName);

	std::string LastName;
	std::cout << "Last Name : ";
	std::getline(std::cin, LastName);

	std::string NickName;
	std::cout << "Nickname : ";
	std::getline(std::cin, NickName);

	std::string PhoneNumber;
	std::cout << "Number : ";
	std::getline(std::cin, PhoneNumber);

	std::string DarkestSecret;
	std::cout << "Darkest Secret : ";
	std::getline(std::cin, DarkestSecret);

    this->Contacts[this->i++] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);
    if (this->i > 7) {this->i = 0;}
}

static std::string cut(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::search() {
    for (int i = 0; i < 8; i++){
        std::cout << std::right << std::setw(10) << i + 1;
        std::cout << "|";
        std::cout << std::right << std::setw(10) << cut(this->Contacts[i].FirstName);
        std::cout << "|";
        std::cout << std::right << std::setw(10) << cut(this->Contacts[i].LastName);
        std::cout << "|";
        std::cout << std::right << std::setw(10) << cut(this->Contacts[i].NickName);
        std::cout << "|" << std::endl;
    }
    int index;
    std::string input;
    while (true){
        std::cout << "Which contact would you like to get the information of?" << std::endl;
        std::getline(std::cin, input);
        std::stringstream myStream(input);
        if (std::cin.eof())
            exit(0);
        if (myStream >> index)
            if (index > 0 && index < 9)
                break;
        std::cout << "Invalid index, try again" << std::endl;
    }
    if (index < 1 || index > 8){
        std::cout << "Invalid index, try again" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        return ;
    }
    std::cout << "Contact" << " : " << index << std::endl;
    std::cout << "First Name" << " : " << this->Contacts[index - 1].FirstName << std::endl;
    std::cout << "Last Name" << " : " << this->Contacts[index - 1].LastName << std::endl;
    std::cout << "Nickname" << " : " << this->Contacts[index - 1].NickName << std::endl;
    std::cout << "Phone Number" << " : " << this->Contacts[index - 1].PhoneNumber << std::endl;
    std::cout << "Darkest Secret" << " : " << this->Contacts[index - 1].DarkestSecret << std::endl;
}