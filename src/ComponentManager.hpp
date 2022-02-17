/*
** EPITECH PROJECT, 2022
** nanotekspice
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
    #define COMPONENTMANAGER_HPP_
    #include <memory>
    #include "IComponent.hpp"

class ComponentManager {
    public:
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

    private:
        std::unique_ptr <nts::IComponent> create4001() const;
        std::unique_ptr <nts::IComponent> create4013() const;
        std::unique_ptr <nts::IComponent> create4040() const;
};

#endif /* !COMPONENTMANAGER_HPP_ */
