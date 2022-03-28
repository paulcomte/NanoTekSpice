/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NOT
*/

#include "NOT.hpp"

namespace nts {

    NOT::~NOT() {

    }

    void NOT::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate NOT::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void NOT::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin == 0 || otherPin == 0 || pin > 15)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void NOT::dump() const {
    }

}