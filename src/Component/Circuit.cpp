/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

namespace nts {

    Circuit::Circuit(std::map<std::string, std::shared_ptr<nts::IComponent>> components) : _components(components) {
        this->_ticks = 0;
    }

    Circuit::~Circuit() {
    }

    size_t Circuit::getTicks() {
        return (this->_ticks);
    }

    std::map<std::string, std::shared_ptr<nts::IComponent>> Circuit::getComponents() {
        return (this->_components);
    }


    std::string Circuit::getFormatedInputs() {
        return ("");
    }

    std::string Circuit::getFormatedOutputs() {
        return ("");
    }

}