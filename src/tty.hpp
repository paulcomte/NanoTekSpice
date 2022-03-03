/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-tekspice-paul.comte
** File description:
** tty
*/

#ifndef TTY_HPP_
#define TTY_HPP_

    #include "unistd.h"
    #include "stdio.h"
    #include <iostream>

class Tty {
    public:
        static bool is_tty(void);
        static void is_command(std::string command);
};

#endif /* !TTY_HPP_ */
