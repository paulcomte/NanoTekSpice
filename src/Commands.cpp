/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Commands
*/

#include "Commands.hpp"
#include <iostream>

namespace Commands {

    void display() {
        std::cout << "tick:" << std::endl;
        std::cout << "input(s):";
        std::cout << std::endl;
        std::cout << "output(s):";
        std::cout << std::endl;
    }

    void exit() {
        std::exit(0);
    }

    void simulate() {
        
    }

};
