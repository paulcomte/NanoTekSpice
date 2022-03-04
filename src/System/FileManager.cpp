/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** FileManager
*/

#include "FileManager.hpp"

FileManager::FileManager(std::string const filepath) : _filepath(filepath) {}

std::vector<std::string> FileManager::readFile() {
    if (!this->_hasValidName())
        throw FileManager::Error("Invalid filepath: [" + this->_filepath + std::string("] is too short or does not end with '.nts'"));
    if (!this->_isInteractable())
        throw FileManager::Error("Invalid permissions: [" + this->_filepath + std::string("] can not be opened or read."));
    return (this->_getContent());
}

bool FileManager::_hasValidName() const {
    if (this->_filepath.size() <= 4)
        return (false);
    if(this->_filepath.compare(this->_filepath.size() - 4, 4, ".nts"))
        return (false);
    return (true);
}

bool FileManager::_isInteractable() const {
    return (access(this->_filepath.c_str(), R_OK) == 0);
}

std::string FileManager::removeRemnantSpaces(std::string &string) const {
    std::regex regexp(" +");
    return (regex_replace(string, regexp, " "));
}

std::vector<std::string> FileManager::_getContent() {
    std::vector<std::string> content;

    std::string line;
    this->_file.open(this->_filepath, std::ios::out);
    while (std::getline(this->_file, line)) {
        if (line.compare(0, 1, "#") == 0)
            continue;
        if (line == "")
            continue;
        line = line.substr(0, line.find('#'));
        content.push_back(removeRemnantSpaces(line));
    }
    this->_file.close();
    return (content);
}
