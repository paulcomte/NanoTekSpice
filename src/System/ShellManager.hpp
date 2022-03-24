/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** ShellManager
*/

#ifndef SHELLMANAGER_HPP_
    #define SHELLMANAGER_HPP_
    #include <string>
    #include <unistd.h>
    #include <vector>
    #include <memory>
    #include <any>
    #include <utility>
    #include "ICommand.hpp"
    #include "../Component/ComponentManager.hpp"

class ShellManager {
    public:
        ShellManager(ComponentManager &componentManager);
        ~ShellManager() {}
        void runShell();

        class Error : public std::exception {
            public:

                Error(std::string message) : _message(message) {}

                char const *what() const noexcept override {
                    return (this->_message).c_str();
                }

            private:
                std::string const _message;
        };

        class Exit : public std::exception {
            public:

                Exit(std::string message) : _message(message) {}

                char const *what() const noexcept override {
                    return (this->_message).c_str();
                }

            private:
                std::string const _message;
        };

        nts::Circuit getCircuit();
        size_t getTicks() const;
        void addTick();

    private:
        ComponentManager _componentManager;
        std::vector<std::unique_ptr<ICommand>> _commands;
        ICommand *_retrieveCommand(std::string commandName);
        void _parseCommand(std::string command);
        bool _parseInput(std::string command);
        size_t _ticks;
};

#endif /* !SHELLMANAGER_HPP_ */
