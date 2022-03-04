/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-tekspice-paul.comte
** File description:
** ICommand
*/

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_
    #include <string>

class ICommand {
    public:
        ICommand(void (*action)(), std::string name) : _action(action), _name(name) {}
        void execute() {_action();};
        std::string getName() {return this->_name;};
    
    private:
        void (*_action)();
        std::string _name;

};

#endif /* !ICOMMAND_HPP_ */
