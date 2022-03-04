/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

False::False(std::string const name) : _name(name) {}

False::~False() {}

IChipset::Type False::getType() {
    return (Type::FALSE);
}

std::string False::getName() {
    return (this->_name);
}
