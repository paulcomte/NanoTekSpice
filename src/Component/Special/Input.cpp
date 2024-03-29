/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"
#include "../../System/ShellManager.hpp"

namespace nts {

    Input::Input() {
        this->_state = Tristate::UNDEFINED;
        this->_newState = Tristate::UNDEFINED;
    }

    Input::~Input() {

    }

    void Input::setValue(std::string value) {
        if (value == "U")
            this->_newState = Tristate::UNDEFINED;
        else if (value == "0")
            this->_newState = Tristate::FALSE;
        else if (value == "1")
            this->_newState = Tristate::TRUE;
        else
            throw ShellManager::Error("[" + value + "] is not a known input state!");
    }

    Tristate Input::getValue() const {
        return (this->_state);
    }

    void Input::simulate(std::size_t tick) {
        (void) tick;
        this->_state = this->_newState;
    }

    Tristate Input::compute(std::size_t pin) {
        if (pin == 0)
            return (UNDEFINED);
        return (this->_state);
    }

    void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void Input::dump() const {

    }

}