/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** OR
*/

#include "OR.hpp"

namespace nts {

    OR::OR() {
        for (int i = 0; i < 15; i++)
            this->_pins[i] = Link(nullptr, 0);
    }

    OR::~OR() {

    }

    void OR::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate OR::_process(std::size_t pin1, std::size_t pin2) {
        Tristate state1;
        Tristate state2;

        if (this->_pins[pin1-1].getComponent() == nullptr || this->_pins[pin2-1].getComponent() == nullptr)
            return (UNDEFINED);
        state1 = this->_pins[pin1-1].getComponent()->compute(this->_pins[pin1-1].getPin());
        state2 = this->_pins[pin2-1].getComponent()->compute(this->_pins[pin2-1].getPin());
        if (state1 == UNDEFINED && state2 == UNDEFINED)
            return (UNDEFINED);
        if (state1 == TRUE || state2 == TRUE)
            return (TRUE);
        if (state1 == UNDEFINED || state2 == UNDEFINED)
            return (UNDEFINED);
        return (FALSE);
    }


    Tristate OR::compute(std::size_t pin) {
        if (pin == 3)
            return (this->_process(1, 2));
        if (pin == 4)
            return (this->_process(5, 6));
        if (pin == 10)
            return (this->_process(8, 9));
        if (pin == 11)
            return (this->_process(12, 13));
        return (Tristate::UNDEFINED);
    }

    void OR::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin == 0 || otherPin == 0 || pin > 15)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void OR::dump() const {
    }

}