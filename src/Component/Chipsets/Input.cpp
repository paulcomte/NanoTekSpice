/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string const name) : _name(name) {}

Input::~Input() {}

IChipset::Type Input::getType() {
    return (Type::INPUT);
}

std::string Input::getName() {
    return (this->_name);
}
