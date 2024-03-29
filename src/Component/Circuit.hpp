/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_
    #include <string>
    #include <map>
    #include <memory>
    #include "IComponent.hpp"

namespace nts {

    class Input;
    class Clock;
    class True;
    class False;

    class Circuit {
        public:
            Circuit(std::map<std::string, std::shared_ptr<nts::IComponent>> components = {});
            ~Circuit();

            std::map<std::string, std::shared_ptr<nts::IComponent>> getComponents() const;

            std::string getFormatedInputs() const;

            std::string getFormatedOutputs() const;

            void simulate();

        private:
            std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
            std::string _getStateName(Tristate value) const;
    };

}

#endif /* !CIRCUIT_HPP_ */
