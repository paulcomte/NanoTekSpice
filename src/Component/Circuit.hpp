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

    class Circuit {
        public:
            Circuit(std::map<std::string, std::shared_ptr<nts::IComponent>> components = {});
            ~Circuit();

            std::map<std::string, std::shared_ptr<nts::IComponent>> getComponents();
            size_t getTicks();

            std::string getFormatedInputs();

            std::string getFormatedOutputs();

        private:
            std::map<std::string, std::shared_ptr<nts::IComponent>> _components;
            size_t _ticks;
    };

}

#endif /* !CIRCUIT_HPP_ */
