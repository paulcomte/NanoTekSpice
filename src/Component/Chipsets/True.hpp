/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** True
*/

#ifndef TRUE_HPP_
    #define TRUE_HPP_
    #include "IChipset.hpp"

class True : public IChipset {
    public:
        True(std::string const _name);
        ~True() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !TRUE_HPP_ */
