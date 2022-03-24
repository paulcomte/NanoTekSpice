/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_
    #include "IComponent.hpp"

namespace nts {

    class Component : public IComponent {
        public:
            ~Component() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
    };

}
#endif /* !COMPONENT_HPP_ */
