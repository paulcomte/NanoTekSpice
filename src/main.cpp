/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main file
*/

#include "System/ShellManager.hpp"
#include "System/FileManager.hpp"
#include "Component/ComponentManager.hpp"
#include <iostream>

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
        std::cerr << "FILE MANAGER ERROR | " << error.what() << std::endl;
        return (84);
    }

    try {
        ComponentManager componentManager(fileContent);
        ShellManager shell(componentManager);
        shell.runShell();
    } catch (ComponentManager::Error const &error) {
        std::cerr << "COMPONENT MANAGER ERROR | " << error.what() << std::endl;
        return (84);
    }

    return (0);
}