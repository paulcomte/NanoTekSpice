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
    }

    Clock::~Clock() {

    }

    void Clock::setValue(std::string value) {
        if (value == "U")
            this->_state = Tristate::UNDEFINED;
        else if (value == "0")
            this->_state = Tristate::FALSE;
        else if (value == "1")
            this->_state = Tristate::TRUE;
        else
            throw ShellManager::Error("[" + value + "] is not a known clock state!");
    }

    Tristate Clock::getValue() const {
        return (this->_state);
    }

    void Clock::simulate(std::size_t tick) {
        (void) tick;
    }

    Tristate Clock::compute(std::size_t pin) {
        (void) pin;
        return (FALSE);
    }

    void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
        if (pin != 1)
            throw ComponentManager::Error("Invalid pin");
        this->_pins[--pin] = Link(&other, otherPin);
    }

    void Clock::dump() const {

    }

}