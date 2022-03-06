/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

namespace nts {

    Output::Output() {
        this->_state = Tristate::UNDEFINED;
    }

    Output::~Output() {

    }

    void Output::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate Output::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void Output::dump() const {

    }

    Tristate Output::getValue() const {
        return (this->_state);
    }

}