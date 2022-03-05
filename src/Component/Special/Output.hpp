/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
    #define OUTPUT_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class Output : public IComponent {
        public:
            Output();
            ~Output() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            Link _pins[1];
    };

}

#endif /* !OUTPUT_HPP_ */
