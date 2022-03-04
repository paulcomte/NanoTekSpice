/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_
    #include "IChipset.hpp"

class Clock : public IChipset {
    public:
        Clock(std::string const _name);
        ~Clock() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !CLOCK_HPP_ */
