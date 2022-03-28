/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NOT
*/

#include "NOT.hpp"

namespace nts {

    NOT::NOT() {
        for (int i = 0; i < 15; i++)
            this->_pins[i] = Link(nullptr, 0);
    }

    NOT::~NOT() {

    }

    void NOT::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate NOT::_process(std::size_t pin1) {
        Tristate state1;

        if (this->_pins[pin1-1].getComponent() == nullptr)
            return (UNDEFINED);
        state1 = this->_pins[pin1-1].getComponent()->compute(this->_pins[pin1-1].getPin());
        if (state1 == UNDEFINED)
            return (UNDEFINED);
        return (state1 == TRUE ? FALSE : TRUE);
    }


    Tristate NOT::compute(std::size_t pin) {
        if (pin == 0)
            return (UNDEFINED);
        if (pin == 2)
            return (this->_process(1));
        if (pin == 4)
            return (this->_process(3));
        if (pin == 6)
            return (this->_process(5));
        if (pin == 8)
            return (this->_process(9));
        if (pin == 10)
            return (this->_process(11));
        if (pin == 12)
            return (this->_process(13));
        return (Tristate::UNDEFINED);
    }

    void NOT::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin == 0 || otherPin == 0 || pin > 15)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void NOT::dump() const {
    }

}