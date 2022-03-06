/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
    #define COMMANDS_HPP_

class ShellManager;

namespace Commands {
    void display(ShellManager &shellmanager);
    void exit(ShellManager &shellmanager);
    void simulate(ShellManager &shellmanager);
};

#endif /* !COMMANDS_HPP_ */
