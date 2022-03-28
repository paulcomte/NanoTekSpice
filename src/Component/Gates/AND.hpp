/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** AND
*/

#ifndef AND_HPP_
    #define AND_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class AND : public IComponent {
            public:
                AND();
                ~AND() override;
                void simulate(std::size_t tick) override;
                Tristate compute(std::size_t pin) override;
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
                void dump() const override;

            private:
                Link _pins[15];
                Tristate _process(std::size_t pin1, std::size_t pin2);
    };
}

#endif /* !AND_HPP_ */
