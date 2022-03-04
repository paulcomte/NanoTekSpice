/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
    #define OUTPUT_HPP_
    #include "IChipset.hpp"

class Output : public IChipset {
    public:
        Output(std::string const _name);
        ~Output() override;

        Type getType() override;
        std::string getName() override;

    private:
        std::string const _name;
};

#endif /* !OUTPUT_HPP_ */
