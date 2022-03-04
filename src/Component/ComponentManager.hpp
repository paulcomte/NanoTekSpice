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
};

#endif /* !COMPONENTMANAGER_HPP_ */
