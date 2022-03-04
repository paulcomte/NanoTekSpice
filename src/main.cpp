/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main file
*/

#include "System/ShellManager.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "nanotekspice: Usage: ./nanotekspice file" << std::endl;
        return (84);
    }
    ShellManager shell;
    shell.runShell();
    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "nanotekspice: " << argv[1] << ": No such file or directory" << std::endl;
        return (84);
    }
    file.close();
    return (0);
}