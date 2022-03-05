/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

namespace nts {

    False::False() {
    }

    False::~False() {

    }

    void False::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate False::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void False::dump() const {

    }

}