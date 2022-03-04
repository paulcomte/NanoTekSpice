/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string const name) : _name(name) {}

Output::~Output() {}

IChipset::Type Output::getType() {
    return (Type::OUTPUT);
}

std::string Output::getName() {
    return (this->_name);
}
