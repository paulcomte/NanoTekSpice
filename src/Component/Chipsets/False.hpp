/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** False
*/

#ifndef FALSE_HPP_
    #define FALSE_HPP_
    #include "IChipset.hpp"

class False : public IChipset {
    public:
        False(std::string const _name);
        ~False() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !FALSE_HPP_ */
