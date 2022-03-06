/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

namespace nts {

    Input::Input() {
    }

    Input::~Input() {

    }

    void Input::setValue(Tristate state) {
        this->_state = state;
    }

    void Input::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate Input::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void Input::dump() const {

    }

}