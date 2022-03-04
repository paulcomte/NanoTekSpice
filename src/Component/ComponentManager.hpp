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
    #include "Chipsets/IChipset.hpp"
    #include "Chipsets/Input.hpp"
    #include "Chipsets/Output.hpp"
    #include "Chipsets/True.hpp"
    #include "Chipsets/False.hpp"
    #include "Chipsets/Clock.hpp"
    #include "Chipsets/4040.hpp"

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
        std::vector<std::unique_ptr<IChipset>> _createChipsets();
};

#endif /* !COMPONENTMANAGER_HPP_ */
