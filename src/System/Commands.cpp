/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Commands
*/

#include "Commands.hpp"
#include "ShellManager.hpp"
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
        throw ShellManager::Exit("");
    }

    void simulate() {
        
    }

};
