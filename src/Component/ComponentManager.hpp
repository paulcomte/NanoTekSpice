/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
    #define COMPONENTMANAGER_HPP_
    #include <string>
    #include <vector>
    #include <map>
    #include <memory>
    #include <regex>
    #include "IComponent.hpp"
    #include "Chipsets/4040.hpp"
    #include "Special/Clock.hpp"
    #include "Special/Output.hpp"
    #include "Special/Input.hpp"
    #include "Special/True.hpp"
    #include "Special/False.hpp"

class ComponentManager {
    public:
        ComponentManager(std::vector<std::string> file);
        ~ComponentManager() {}

        class Error : public std::exception {
            public:

                Error(std::string message) : _message(message) {}

                char const *what() const noexcept override {
                    return (this->_message).c_str();
                }

            private:
                std::string const _message;
        };

    private:
        std::vector<std::string> _file;
        bool _isFileValid();
        std::string _retrieveFileContent();
        std::vector<std::string> _retrieveChipsets();
        std::vector<std::string> _retrieveLinks();
        std::map<std::string, std::unique_ptr<nts::IComponent>> _createChipsets();
        void _createLinks(std::map<std::string, std::unique_ptr<nts::IComponent>> &chipsets);
};

#endif /* !COMPONENTMANAGER_HPP_ */
