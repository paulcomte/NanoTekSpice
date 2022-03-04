/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"
#include <iostream>

ComponentManager::ComponentManager(std::vector<std::string> file) : _file(file) {
    if (!this->_isFileValid())
        throw Error("Invalid file:\n[" + this->_retrieveFileContent() + std::string("] chipsets and or links number is invalid"));
    // TODO add different circuits
}

bool ComponentManager::_isFileValid() {
    int chipsets = 0;
    int links = 0;

    for (std::string string : this->_file) {
        if (string == ".chipsets:")
            chipsets++;
        if (string == ".links:")
            links++;
    }
    return (chipsets == 1 && links == 1);
}

std::string ComponentManager::_retrieveFileContent() {
    std::string content;

    for (std::string string : this->_file) {
        content += string;
        content += "\n";
    }
    return (content);
}


std::vector<std::string> ComponentManager::_retrieveChipsets() {
    std::vector<std::string> chipsets;
    bool isInChipsets = false;

    for (std::string string : this->_file) {
        if (string == ".chipsets:") {
            isInChipsets = true;
            continue;
        }
        if (string == ".links:" && isInChipsets)
            return (chipsets);
        if (isInChipsets)
            chipsets.push_back(string);
    }
    return (chipsets);
}

std::vector<std::string> ComponentManager::_retrieveLinks() {
    std::vector<std::string> links;
    bool isInLinks = false;

    for (std::string string : this->_file) {
        if (string == ".links:") {
            isInLinks = true;
            continue;
        }
        if (string == ".chipsets:" && isInLinks)
            return (links);
        if (isInLinks)
            links.push_back(string);
    }
    return (links);
}
