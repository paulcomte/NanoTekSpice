/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** main file
*/

#include "IComponent.hpp"
#include "ComponentManager.hpp"
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "nanotekspice: Usage: ./nanotekspice file" << std::endl;
        return (84);
    }
    std::ifstream file(argv[1]);
    std::string line;

    if (!file.is_open())
        std::cerr << "nanotekspice: " << argv[1] << ": No such file or directory" << std::endl;
    std::cout << file.rdbuf();
    file.close();
    return (0);
}