/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** 4040
*/

#include "4040.hpp"

TWELVE_BITS_COUNTER::TWELVE_BITS_COUNTER(std::string const name) : _name(name) {}

TWELVE_BITS_COUNTER::~TWELVE_BITS_COUNTER() {}

IChipset::Type TWELVE_BITS_COUNTER::getType() {
    return (Type::TWELVE_BITS_COUNTER);
}

std::string TWELVE_BITS_COUNTER::getName() {
    return (this->_name);
}
