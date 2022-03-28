/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NOR
*/

#ifndef NOR_HPP_
    #define NOR_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class NOR : public IComponent {
            public:
                ~NOR() override;
                void simulate(std::size_t tick) override;
                Tristate compute(std::size_t pin) override;
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
                void dump() const override;

            private:
                Link _pins[15];
                Tristate _process(std::size_t pin1, std::size_t pin2);
    };
}

#endif /* !NOR_HPP_ */
