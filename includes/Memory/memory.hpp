/*
** EPITECH PROJECT, 2021
** ram
** File description:
** emulation
*/

#pragma once
#include "../CPU/cpu.hpp"
#include <stack>

class Memory
{
    public:
        Memory() {
            for (int i = 0; i <= 15; i++)
                registers.push_back(std::make_pair(nullptr, eOperandType::None));
        }
        void push_value(IOperand *v);
        bool pop_top();
        void clear();
        void dup();
        bool swap();
        void dump(std::stack<IOperand*>);
        bool assert(std::pair<eOperandType, std::string>);
        bool store(std::pair<eOperandType, std::string>);
        bool load(std::pair<eOperandType, std::string>);
        bool print();
        std::stack<IOperand*> _stack;
        std::vector<std::pair<IOperand*, eOperandType>> registers;
};