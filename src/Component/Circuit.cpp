/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Special/Input.hpp"
#include "Special/Clock.hpp"
#include "Special/Output.hpp"
#include <vector>

namespace nts {

    Circuit::Circuit(std::map<std::string, std::shared_ptr<nts::IComponent>> components) : _components(components) {}

    Circuit::~Circuit() {
    }

    std::map<std::string, std::shared_ptr<nts::IComponent>> Circuit::getComponents() const {
        return (this->_components);
    }


    std::string Circuit::getFormatedInputs() const {
        std::vector<std::string> inputs;
        std::string result;
        for (auto const &v : this->getComponents()) {
            nts::Input *input = dynamic_cast<nts::Input*>(this->getComponents()[v.first].get());
            if (input == nullptr) {
                nts::Clock *clock = dynamic_cast<nts::Clock*>(this->getComponents()[v.first].get());
                if (clock == nullptr)
                    continue;
                inputs.push_back(v.first + std::string(": ") + this->_getStateName(clock->getValue()));
                continue;
            }
            inputs.push_back(v.first + std::string(": ") + this->_getStateName(input->getValue()));
        }
        std::sort(inputs.begin(), inputs.end());
        for (std::string str : inputs) {
            result += "\n";
            result += "  " + str;
        }
        return (result);
    }

    std::string Circuit::getFormatedOutputs() const {
        std::vector<std::string> outputs;
        std::string result;
        for (auto const &v : this->getComponents()) {
            nts::Output *output = dynamic_cast<nts::Output*>(this->getComponents()[v.first].get());
            if (output == nullptr)
                    continue;
            outputs.push_back(v.first + std::string(": ") + this->_getStateName(output->getValue()));
        }
        std::sort(outputs.begin(), outputs.end());
        for (std::string str : outputs) {
            result += "\n";
            result += "  " + str;
        }
        return (result);
    }

    std::string Circuit::_getStateName(Tristate value) const {
        if (value == UNDEFINED)
            return "U";
        if (value == TRUE)
            return ("1");
        if (value == FALSE)
            return ("0");
        return ("U");
    }

    void Circuit::simulate() {
        for (auto const &v : this->getComponents())
            v.second.get()->simulate(1);
    }

}