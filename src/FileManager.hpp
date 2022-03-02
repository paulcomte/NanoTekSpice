/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** File Manager
*/

#ifndef FILEMANAGER_HPP_
    #define FILEMANAGER_HPP_
    
    #include <fstream>
    #include "ComponentManager.hpp"

std::unique_ptr<nts::IComponent> parseFile(std::ifstream &file);

#endif /* !FILEMANAGER_HPP_ */
