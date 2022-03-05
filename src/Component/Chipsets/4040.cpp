/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** 4040
*/

#include "4040.hpp"

namespace nts {

    TWELVE_BITS_COUNTER::~TWELVE_BITS_COUNTER() {

    }

    void TWELVE_BITS_COUNTER::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate TWELVE_BITS_COUNTER::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void TWELVE_BITS_COUNTER::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin == 0 || otherPin == 0 || pin > 15)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void TWELVE_BITS_COUNTER::dump() const {
    }

}