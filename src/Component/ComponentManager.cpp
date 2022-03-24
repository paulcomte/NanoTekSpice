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
    std::map<std::string, std::shared_ptr<nts::IComponent>> _components = this->_createChipsets();
    this->_circuit = nts::Circuit(this->_createLinks(_components));
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

std::map<std::string, std::shared_ptr<nts::IComponent>> ComponentManager::_createChipsets() {
    std::vector<std::string> rawChipsets = this->_retrieveChipsets();
    std::map<std::string, std::shared_ptr<nts::IComponent>> chipsets;

    for (std::string raw : rawChipsets) {
        std::string type = raw.substr(0, raw.find(" "));
        std::string name = raw.substr(raw.find(" ") + 1, raw.size());
        if (raw.find(" ") > raw.size())
            throw ComponentManager::Error("Invalid syntax: " + std::string("[") + type + std::string(":") + name + std::string("]"));
        if (chipsets[name] != nullptr)
            throw ComponentManager::Error("Invalid name: " + name + " already exists");
        if (type == "input")
            chipsets[name] = std::unique_ptr<nts::Input>(new nts::Input());
        else if (type == "output")
            chipsets[name] = std::unique_ptr<nts::Output>(new nts::Output());
        else if (type == "clock")
            chipsets[name] = std::unique_ptr<nts::Clock>(new nts::Clock());
        else if (type == "true")
            chipsets[name] = std::unique_ptr<nts::True>(new nts::True());
        else if (type == "false")
            chipsets[name] = std::unique_ptr<nts::False>(new nts::False());
        else if (type == "4040")
            chipsets[name] = std::unique_ptr<nts::TWELVE_BITS_COUNTER>(new nts::TWELVE_BITS_COUNTER());
        else
            throw ComponentManager::Error("Invalid type: " + type + " is not a known type");
    }
    return (chipsets);
}

std::map<std::string, std::shared_ptr<nts::IComponent>> ComponentManager::_createLinks(std::map<std::string, std::shared_ptr<nts::IComponent>> &chipsets) {
    std::vector<std::string> rawLinks = this->_retrieveLinks();
    std::string specialName;
    std::size_t pin;
    std::string gateName;
    std::size_t gatePin;

    for (std::string raw : rawLinks) {
        std::smatch m;
        std::regex_search(raw, m, std::regex(".+?(?=:)"));
        if (m.size() != 1)
            throw ComponentManager::Error("Unknown name");
        specialName = m[0];
        std::regex_search(raw, m, std::regex("(?:.*?[:]+){1}.*?([:0-9.]+)"));
        if (m.size() != 2)
            throw ComponentManager::Error("Unknown pin");
        pin = std::atol((static_cast<std::string> (m[1])).c_str());
        std::regex_search(raw, m, std::regex("(?= ).+?(?=:)"));
        if (m.size() != 1)
            throw ComponentManager::Error("Unknown gate name");
        gateName = ((std::string) m[0]).substr(1);
        std::regex_search(raw, m, std::regex("(?:.*?[:]+){2}.*?([:0-9.]+)"));
        if (m.size() != 2)
            throw ComponentManager::Error("Unknown gate pin");
        gatePin = std::atol(((std::string) m[1]).c_str());
        if (chipsets[gateName] == nullptr || chipsets[specialName] == nullptr)
            throw ComponentManager::Error("Component name unknown");
        chipsets[gateName].get()->setLink(gatePin, *chipsets[specialName].get(), pin);
        chipsets[specialName].get()->setLink(pin, *chipsets[gateName].get(), gatePin);
    }
    return (chipsets);
}

nts::Circuit ComponentManager::getCircuit() {
    return (this->_circuit);
}