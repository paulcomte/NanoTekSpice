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

std::vector<std::unique_ptr<IChipset>> ComponentManager::_createChipsets() {
    std::vector<std::string> rawChipsets = this->_retrieveChipsets();
    std::vector<std::unique_ptr<IChipset>> chipsets;

    for (std::string raw : rawChipsets) {
        std::string type = raw.substr(0, raw.find(" "));
        std::string name = raw.substr(raw.find(" ") + 1, raw.size());
        if (raw.find(" ") > raw.size())
            throw ComponentManager::Error("Invalid syntax: " + std::string("[") + type + std::string(":") + name + std::string("]"));
        for (std::unique_ptr<IChipset> &chipset : chipsets)
            if (chipset.get()->getName() == name)
                throw ComponentManager::Error("Invalid name: " + name + " already exists");
        if (type == "input")
            chipsets.push_back(std::unique_ptr<IChipset>(new Input(name)));
        else if (type == "output")
            chipsets.push_back(std::unique_ptr<IChipset>(new Output(name)));
        else if (type == "clock")
            chipsets.push_back(std::unique_ptr<IChipset>(new Clock(name)));
        else if (type == "true")
            chipsets.push_back(std::unique_ptr<IChipset>(new True(name)));
        else if (type == "false")
            chipsets.push_back(std::unique_ptr<IChipset>(new False(name)));
        else if (type == "4040")
            chipsets.push_back(std::unique_ptr<IChipset>(new False(name)));
        else
            throw ComponentManager::Error("Invalid type: " + type + " is not a known type");
    }
    return (chipsets);
}
