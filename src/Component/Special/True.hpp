/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** True
*/

#ifndef TRUE_HPP_
    #define TRUE_HPP_
    #include <map>
    #include "../Component.hpp"
    #include "../ComponentManager.hpp"
    #include "../Link.hpp"

namespace nts {

    class True : public Component {
        public:
            True();
            ~True() override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            Link _pins[1];
    };

}

#endif /* !TRUE_HPP_ */
