/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** IChipset
*/

#ifndef ICHIPSET_HPP_
    #define ICHIPSET_HPP_
    #include "../IComponent.hpp"

class IChipset {
    public:

        enum Type {
            INPUT,
            OUTPUT,
            CLOCK,
            TRUE,
            FALSE,
            TWELVE_BITS_COUNTER
        };

        virtual ~IChipset() {}

        virtual Type getType() = 0;
        virtual std::string getName() = 0;
};

#endif /* !ICHIPSET_HPP_ */
