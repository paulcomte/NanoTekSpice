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

    void display(ShellManager &shellManager) {
        (void) shellManager;
        std::cout
            << "tick: " << shellManager.getCircuit().getTicks() << std::endl
            << "input(s):"
            << std::endl
            << "output(s):"
            << std::endl;
    }

    void exit(ShellManager &shellManager) {
        (void) shellManager;
        throw ShellManager::Exit("");
    }

    void simulate(ShellManager &shellManager) {
        (void) shellManager;
    }

};
