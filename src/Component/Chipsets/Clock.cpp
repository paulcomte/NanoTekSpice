/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const name) : _name(name) {}

Clock::~Clock() {}

IChipset::Type Clock::getType() {
    return (Type::CLOCK);
}

std::string Clock::getName() {
    return (this->_name);
}
