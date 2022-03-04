/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main file
*/

#include "System/ShellManager.hpp"
#include "System/FileManager.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "nanotekspice: Usage: ./nanotekspice file" << std::endl;
        return (84);
    }
    FileManager fileManager(argv[1]);
    std::vector<std::string> fileContent;

    try {
        fileContent = fileManager.readFile();
    } catch(FileManager::Error const &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }

    ShellManager shell;
    shell.runShell();
    return (0);
}