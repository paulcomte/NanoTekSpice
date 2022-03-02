/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** file reader
*/

#include "FileManager.hpp"

std::unique_ptr<nts::IComponent> parseFile(std::ifstream &file) {
    std::unique_ptr<nts::IComponent> component;
    std::string line;
    bool is_chipset = false;
    while (std::getline(file, line)) {
        if (line == ".chipsets")
            break;
    }
    if (line != ".chipsets")
        exit(84);
    while (std::getline(file, line)) {
        if (line == "")
            break;
        // ajouter tt les composants
        else {
            is_chipset = true;
            // ajouter le chipset
        }
    }
    while (std::getline(file, line)) {
        // composant tel va dans sa (modif de liste)
    }
    // basics (input / clock / true / false)
    return (component);
}
