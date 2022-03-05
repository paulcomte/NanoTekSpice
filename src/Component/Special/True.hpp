/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** True
*/

#ifndef TRUE_HPP_
    #define TRUE_HPP_
    #include <map>
    #include "../ComponentManager.hpp"
    #include "../IComponent.hpp"
    #include "../Link.hpp"

namespace nts {

    class True : public IComponent {
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
