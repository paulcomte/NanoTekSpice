/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

std::unique_ptr<nts::IComponent> ComponentManager::createComponent(const std::string &type) {
    return (create4001());
}

std::unique_ptr<nts::IComponent> ComponentManager::create4001() const {
    return (nullptr);
}

std::unique_ptr<nts::IComponent> ComponentManager::create4013() const {
    return (nullptr);
}

std::unique_ptr<nts::IComponent> ComponentManager::create4040() const {
    return (nullptr);
}
