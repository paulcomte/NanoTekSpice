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
    #include "ICommand.hpp"

class ShellManager {
    public:
        ShellManager();
        ~ShellManager() {}
        bool isTty();
        void parseCommand(std::string command);
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

    private:
        bool _setTty(void);
        bool _tty;
        std::vector<std::unique_ptr<ICommand>> _commands;
        ICommand *_retrieveCommand(std::string commandName);
};

#endif /* !SHELLMANAGER_HPP_ */
