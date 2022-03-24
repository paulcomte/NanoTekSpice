/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** ShellManager
*/

#include "ShellManager.hpp"
#include "Commands.hpp"
#include <iostream>
#include <fstream>

ShellManager::ShellManager(ComponentManager &componentManager) : _componentManager(componentManager) {
    this->_ticks = 0;
    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::display, std::string("display"))));
    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::exit, std::string("exit"))));
    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::simulate, std::string("simulate"))));
}

void ShellManager::runShell() {
    std::string line;

    std::cout << "> ";
    if (!(std::getline(std::cin, line)))
        return;
    try {
        if (!this->_parseInput(line))
            this->_parseCommand(line);
    } catch (ShellManager::Error const &error) {
        std::cerr << "SHELL MANAGER ERROR | " << error.what() << std::endl;
    } catch (ShellManager::Exit const &ignored) {
        return;
    }
    runShell();
}

bool ShellManager::_parseInput(std::string command) {
    std::string component;
    std::string value;

    std::smatch m;
    std::regex_search(command, m, std::regex(".+?(?==)"));
    if (m.size() != 1)
        return (false);
    component = m[0];
    if (command.size() < component.size()+2)
        return (false);
    value = command.substr(component.size()+1);
    if (command != component + "=" + value)
        return (false);

    if (this->getCircuit().getComponents()[component] == nullptr)
        throw ShellManager::Error("[" + component + "] is not a known component!");

    nts::Input *input = dynamic_cast<nts::Input*>(this->getCircuit().getComponents()[component].get());
    if (input == nullptr) {
        nts::Clock *clock = dynamic_cast<nts::Clock*>(this->getCircuit().getComponents()[component].get());
        if (clock == nullptr)
            throw ShellManager::Error("[" + component + "] is not an input/clock!");
        clock->setValue(value);
        return (true);
    }
    input->setValue(value);
    return (true);
}

void ShellManager::_parseCommand(std::string commandName)
{
    ICommand *command = this->_retrieveCommand(commandName);

    if (command == nullptr)
        throw ShellManager::Error("Unknown command" + std::string(": ") + commandName + " >> does not exist!");
    command->execute(*this);
}

ICommand *ShellManager::_retrieveCommand(std::string commandName) {
    for(std::unique_ptr<ICommand> &command : this->_commands) {
        if (command.get() != nullptr && command.get()->getName() == commandName)
            return (command.get());
    }
    return (nullptr);
}

nts::Circuit ShellManager::getCircuit() {
    return (this->_componentManager.getCircuit());
}

size_t ShellManager::getTicks() const {
    return (this->_ticks);
}

void ShellManager::addTick() {
    this->_ticks += 1;
}
