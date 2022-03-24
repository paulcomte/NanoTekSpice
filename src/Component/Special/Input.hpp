/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Input
*/

#ifndef INPUT_HPP_
    #define INPUT_HPP_
    #include <map>
    #include "../Component.hpp"
    #include "../Link.hpp"
    #include "../ComponentManager.hpp"

namespace nts {

    class Input : public Component {
        public:
            Input();
            ~Input() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
            void setValue(std::string value);
            Tristate getValue() const;

        private:
            Link _pins[1];
            Tristate _state;
            Tristate _newState;
    };

}

#endif /* !INPUT_HPP_ */
