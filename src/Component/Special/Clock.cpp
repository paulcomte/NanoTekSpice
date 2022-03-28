/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"
#include "../../System/ShellManager.hpp"

namespace nts {

    Clock::Clock() {
        this->_state = Tristate::UNDEFINED;
        this->_hasValue = false;
        this->_newState = Tristate::UNDEFINED;
    }

    Clock::~Clock() {

    }

    void Clock::setValue(std::string value) {
        this->_hasValue = true;
        if (value == "U")
            this->_newState = Tristate::UNDEFINED;
        else if (value == "0")
            this->_newState = Tristate::FALSE;
        else if (value == "1")
            this->_newState = Tristate::TRUE;
        else
            throw ShellManager::Error("[" + value + "] is not a known clock state!");
    }

    Tristate Clock::getValue() const {
        return (this->_state);
    }

    void Clock::simulate(std::size_t tick) {
        (void) tick;
        if (this->_hasValue) {
            this->_hasValue = false;
            this->_state = this->_newState;
            return;
        }
        if (this->_state == Tristate::UNDEFINED)
            return;
        this->_newState = this->_state == Tristate::FALSE ? Tristate::TRUE : Tristate::FALSE;
        this->_state = this->_newState;
    }

    Tristate Clock::compute(std::size_t pin) {
        if (pin == 0)
            return (UNDEFINED);
        return (this->_state);
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void Clock::dump() const {

    }

}