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
        std::cout
            << "tick:" << std::endl
            << "input(s):"
            << std::endl
            << "output(s):"
            << std::endl;
    }

    void exit() {
        std::exit(0);
    }

    void simulate() {
        
    }

};
