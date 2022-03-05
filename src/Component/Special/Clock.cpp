/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"

namespace nts {

    Clock::Clock() {
    }

    Clock::~Clock() {

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