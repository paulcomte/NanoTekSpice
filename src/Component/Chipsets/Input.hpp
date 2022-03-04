/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Input
*/

#ifndef INPUT_HPP_
    #define INPUT_HPP_
    #include "IChipset.hpp"

class Input : public IChipset {
    public:
        Input(std::string const _name);
        ~Input() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !INPUT_HPP_ */
