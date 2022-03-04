/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** FileManager
*/

#ifndef FILEMANAGER_HPP_
    #define FILEMANAGER_HPP_
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <unistd.h>
    #include <vector>
    #include <regex>

class FileManager {
    public:
        FileManager(std::string const filepath);
        ~FileManager() {}

        std::vector<std::string> readFile();

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
        std::string const _filepath;
        std::ifstream _file;
        bool _hasValidName() const;
        bool _isInteractable() const;
        std::vector<std::string> _getContent();
        std::string removeRemnantSpaces(std::string &string) const;
};

#endif /* !FILEMANAGER_HPP_ */
