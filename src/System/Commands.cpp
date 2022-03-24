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
        std::cout
            << "tick: " << shellManager.getTicks() << std::endl
            << "input(s):" << shellManager.getCircuit().getFormatedInputs()
            << std::endl
            << "output(s):" << shellManager.getCircuit().getFormatedOutputs()
            << std::endl;
    }

    void exit(ShellManager &shellManager) {
        (void) shellManager;
        throw ShellManager::Exit("");
    }

    void simulate(ShellManager &shellManager) {
        shellManager.getCircuit().simulate();
        shellManager.addTick();
    }

};
