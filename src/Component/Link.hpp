/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Link
*/

#ifndef LINK_HPP_
    #define LINK_HPP_
    #include <array>
    #include "IComponent.hpp"

namespace nts {

    class Link {
        public:
            Link(IComponent *component = nullptr, std::size_t pin = 0) : _component(component), _pin(pin) {}

            Link &operator=(Link const &link) {
                this->_component = link._component;
                this->_pin = link._pin;
                return (*this);
            }

            IComponent *getComponent() {return (this->_component);};
            std::size_t getPin() {return (this->_pin);};

        private:
            IComponent *_component;
            std::size_t _pin;
    };

}

#endif /* !LINK_HPP_ */
