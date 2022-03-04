/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** 4040
*/

#ifndef TWELVE_BITS_COUNTER_HPP_
    #define TWELVE_BITS_COUNTER_HPP_
    #include "IChipset.hpp"

class TWELVE_BITS_COUNTER : public IChipset {
    public:
        TWELVE_BITS_COUNTER(std::string const _name);
        ~TWELVE_BITS_COUNTER() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !CLOCK_HPP_ */
