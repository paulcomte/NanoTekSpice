/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class Clock : public IComponent {
        public:
            Clock();
            ~Clock() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            Link _pins[1];
    };

}

#endif /* !CLOCK_HPP_ */
