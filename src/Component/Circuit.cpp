/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Special/Input.hpp"
#include "Special/Clock.hpp"
#include "Special/True.hpp"
#include "Special/False.hpp"
#include "Special/Output.hpp"
#include <vector>

namespace nts {

    Circuit::Circuit(std::map<std::string, std::shared_ptr<nts::IComponent>> components) : _components(components) {}

    Circuit::~Circuit() {
    }

    std::map<std::string, std::shared_ptr<nts::IComponent>> Circuit::getComponents() const {
        return (this->_components);
    }

    std::string Circuit::getInputValue(nts::Input const *input) const {
        return (this->_getStateName(input->getValue()));
    }

    std::string Circuit::getInputValue(nts::Clock const *input) const {
        return (this->_getStateName(input->getValue()));
    }

    std::string Circuit::getInputValue(nts::True const *input) const {
        (void) input;
        return (this->_getStateName(Tristate::TRUE));
    }

    std::string Circuit::getInputValue(nts::False const *input) const {
        (void) input;
        return (this->_getStateName(Tristate::FALSE));
    }

    std::string Circuit::getInputValue(nts::IComponent *input) const {
        nts::Input *target = dynamic_cast<nts::Input*>(input);
        if (target != nullptr)
            return (getInputValue(target));
        nts::True *trueTarget = dynamic_cast<nts::True*>(input);
        if (trueTarget != nullptr)
            return (getInputValue(trueTarget));
        nts::False *falseTarget = dynamic_cast<nts::False*>(input);
        if (falseTarget != nullptr)
            return (getInputValue(falseTarget));
        nts::Clock *clockTarget = dynamic_cast<nts::Clock*>(input);
        if (clockTarget != nullptr)
            return (getInputValue(clockTarget));
        return ("");
    }

    std::string Circuit::getFormatedInputs() const {
        std::vector<std::string> inputs;
        std::string result;
        for (auto const &v : this->getComponents()) {
            nts::Output *output = dynamic_cast<nts::Output*>(this->getComponents()[v.first].get());
            if (output != nullptr)
                continue;
            inputs.push_back(v.first + std::string(": ") + getInputValue(this->getComponents()[v.first].get()));
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