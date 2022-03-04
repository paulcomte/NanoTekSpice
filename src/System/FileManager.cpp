/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** FileManager
*/

#include "FileManager.hpp"

FileManager::FileManager(std::string filepath) : _filepath(filepath) {
}

FileManager::~FileManager()
{
}

std::string FileManager::readFile() {
    std::string content;

    if (!this->_hasValidName())
        throw FileManager::Error("Invalid filepath: [" + this->_filepath + std::string("] is too short or does not end with '.nts'"));
    if (!this->_isInteractable())
        throw FileManager::Error("Invalid permissions: [" + this->_filepath + std::string("] can not be opened or read."));

    std::stringstream sStream;
    sStream << this->_file.rdbuf();
    this->_file.open(this->_filepath, std::ios::out);
    content = sStream.str();
    this->_file.close();
    return (content);
}

bool FileManager::_hasValidName() {
    if (this->_filepath.size() <= 4)
        return (false);
    if(this->_filepath.compare(this->_filepath.size() - 4, 4, ".nts"))
        return (false);
    return (true);
}

bool FileManager::_isInteractable() {
    return (access(this->_filepath.c_str(), R_OK) == 0);
}
