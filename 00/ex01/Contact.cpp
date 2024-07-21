/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:31:56 by abataill          #+#    #+#             */
/*   Updated: 2023/12/15 23:17:11 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    this->FirstName = "Empty";
    this->LastName = "Empty";
    this->NickName = "Empty";
    this->PhoneNumber = "Empty";
    this->DarkestSecret = "Empty";
}

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string d) {
    this->FirstName = f;
    this->LastName = l;
    this->NickName = n;
    this->PhoneNumber = p;
    this->DarkestSecret = d;
}

Contact::~Contact() {};