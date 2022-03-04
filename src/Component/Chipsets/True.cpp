/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** True
*/

#include "True.hpp"

True::True(std::string const name) : _name(name) {}

True::~True() {}

IChipset::Type True::getType() {
    return (Type::TRUE);
}

std::string True::getName() {
    return (this->_name);
}
