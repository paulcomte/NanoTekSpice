/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** True
*/

#include "True.hpp"

namespace nts {

    True::True() {
    }

    True::~True() {

    }

    void True::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate True::compute(std::size_t pin) {
        (void) pin;
        return (TRUE);
    }

    void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void True::dump() const {

    }

}