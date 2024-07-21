/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:24:19 by abataill          #+#    #+#             */
/*   Updated: 2023/12/15 23:58:09 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
   public:

   PhoneBook();
   ~PhoneBook();

   void add();
   void search();

   private:
   
   Contact Contacts[8];
   int i;
   
};

#endif