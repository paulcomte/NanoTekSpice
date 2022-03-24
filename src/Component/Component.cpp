/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Component
*/

#include "Component.hpp"

namespace nts {

    Component::~Component() {}

    void Component::simulate(std::size_t tick) {
        (void) tick;
    }

    nts::Tristate Component::compute(std::size_t pin) {
        (void) pin;
        return (Tristate::UNDEFINED);
    }

    void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        (void) pin;
        (void) other;
        (void) otherPin;
    }

    void Component::dump() const {}

}