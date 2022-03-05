/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** 4040
*/

#ifndef TWELVE_BITS_COUNTER_HPP_
    #define TWELVE_BITS_COUNTER_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class TWELVE_BITS_COUNTER : public IComponent {
            public:
                ~TWELVE_BITS_COUNTER() override;
                void simulate(std::size_t tick) override;
                nts::Tristate compute(std::size_t pin) override;
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
                void dump() const override;

            private:
                Link _pins[15];
    };
}

#endif /* !CLOCK_HPP_ */
