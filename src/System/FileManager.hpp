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

class FileManager {
    public:
        FileManager(std::string filepath);
        ~FileManager();

        std::string readFile();

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
        std::string _filepath;
        std::ofstream _file;
        bool _hasValidName();
        bool _isInteractable();
};

#endif /* !FILEMANAGER_HPP_ */
