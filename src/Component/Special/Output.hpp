/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
    #define OUTPUT_HPP_
    #include <map>
    #include "../Component.hpp"
    #include "../ComponentManager.hpp"
    #include "../Link.hpp"

namespace nts {

    class Output : public Component {
        public:
            Output();
            ~Output() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
            Tristate getValue() const;

        private:
            Link _pins[1];
            Tristate _state;
    };

}

#endif /* !OUTPUT_HPP_ */
