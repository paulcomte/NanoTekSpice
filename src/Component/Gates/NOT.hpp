/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NOT
*/

#ifndef NOT_HPP_
    #define NOT_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class NOT : public IComponent {
            public:
                ~NOT() override;
                void simulate(std::size_t tick) override;
                nts::Tristate compute(std::size_t pin) override;
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
                void dump() const override;

            private:
                Link _pins[15];
                Tristate _process(std::size_t pin1);
    };
}

#endif /* !NOT_HPP_ */
