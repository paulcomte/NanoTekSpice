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
        compute(1);
    }

    Tristate Output::compute(std::size_t pin) {
        if (pin == 0)
            return (UNDEFINED);
        if (pin == 1) {
            if (this->_pins->getComponent() == nullptr)
                return (this->_state);
            this->_state = this->_pins->getComponent()->compute(1);
            return (this->_state);
        }
        return (UNDEFINED);
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