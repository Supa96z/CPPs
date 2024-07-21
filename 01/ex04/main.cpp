/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:38:30 by abataill          #+#    #+#             */
/*   Updated: 2024/01/12 23:20:19 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv){
    if (argc != 4){std::cerr << "Error. Check arguments." << std::endl; exit(1);}
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream file(filename);
    if (!file.is_open()){std::cerr << "Error. No file of that name." << std::endl; exit(1);}
    
    std::ofstream newfile(filename + ".replace");
    std::string line;
    
    while (getline(file, line)){
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos){
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        newfile << line << std::endl;
    }
    
    file.close();
}