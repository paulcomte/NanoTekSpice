/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** OR
*/

#include "OR.hpp"

namespace nts {

    OR::~OR() {

    }

    void OR::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate OR::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void OR::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin == 0 || otherPin == 0 || pin > 15)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void OR::dump() const {
    }

}