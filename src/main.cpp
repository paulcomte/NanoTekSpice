/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main file
*/

#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include "FileManager.hpp"
#include <fstream>
#include <iostream>
#include "tty.hpp"
#include <string>


void Tty::is_command(std::string command)
{
    if (command == "exit")
        exit (0);
    if (command == "display") {
        std::cout << "tick:" << std::endl;
        std::cout << "input(s):";
        std::cout << std::endl;
        std::cout << "output(s):";
        std::cout << std::endl;
    }
    if (command == "simulate") {
    }
}

bool Tty::is_tty(void) {
    if (isatty(0))
        return (true);
    return (false);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "nanotekspice: Usage: ./nanotekspice file" << std::endl;
        return (84);
    }
    std::ifstream file(argv[1]);
    std::string line;
    size_t len = 0;

    if (!file.is_open()) {
        std::cerr << "nanotekspice: " << argv[1] << ": No such file or directory" << std::endl;
        return (84);
    }
    file.close();
    if (Tty::is_tty())
        std::cout << "> ";
    while (std::getline(std::cin, line)) {
        Tty::is_command(line);
        if (Tty::is_tty())
            std::cout << "> ";
    }
    return (0);
}