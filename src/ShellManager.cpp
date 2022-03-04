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

ShellManager::ShellManager() {
    this->_tty = _setTty();

    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::display, std::string("display"))));
    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::exit, std::string("exit"))));
    this->_commands.push_back(std::unique_ptr<ICommand>(new ICommand(Commands::simulate, std::string("simulate"))));
}

void ShellManager::runShell() {
    std::string line;

    if (this->isTty())
         std::cout << "> ";
    while (std::getline(std::cin, line)) {
         this->parseCommand(line);
         if (this->isTty())
             std::cout << "> ";
    }
}

void ShellManager::parseCommand(std::string commandName)
{
    ICommand *command = this->_retrieveCommand(commandName);

    if (command == nullptr)
        return;
    command->execute();
}

bool ShellManager::isTty() {
    return (this->_tty);
}

ICommand *ShellManager::_retrieveCommand(std::string commandName) {
    for(std::unique_ptr<ICommand> &command : this->_commands) {
        if (command.get() != nullptr && command.get()->getName() == commandName)
            return (command.get());
    }
    return (nullptr);
}

bool ShellManager::_setTty(void) {
    if (isatty(0))
        return (true);
    return (false);
}
