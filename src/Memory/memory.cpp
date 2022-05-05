/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** Memory.cpp
*/
#include "../../includes/Memory/memory.hpp"

void Memory::push_value(IOperand *v)    
{
    _stack.push(v);
}

bool Memory::pop_top()
{
    if (_stack.empty())
        return (false);
    _stack.pop();
    return (true);
}

void Memory::clear()
{
    while (!_stack.empty()) {
        _stack.pop();
    }
}

void Memory::dup()
{
    IOperand *tmp = _stack.top();
    _stack.push(tmp);
}

bool Memory::swap()
{
    if (_stack.size() < 2)
        return (false);
    IOperand *first_tmp = _stack.top();
    _stack.pop();
    IOperand *second_tmp = _stack.top();
    _stack.pop();
    _stack.push(first_tmp);
    _stack.push(second_tmp);
    return (true);
}

bool findChar(char c, std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (str.at(i) == c)
            return true;
    return false;
}

void Memory::dump(std::stack<IOperand*> stack)
{
    if (stack.empty())
        return;
    IOperand *tmp = stack.top();
    std::string tmpString = tmp->toString();

    if (findChar('.', tmpString)) { //remove zeros after comma
        for (; tmpString.c_str()[tmpString.length() - 1] == '0'; tmpString.erase(tmpString.length() - 1)) {
            if (tmpString.c_str()[tmpString.length() - 2] == '.') {
                tmpString.erase(tmpString.length() - 1);
                tmpString.erase(tmpString.length() - 1);
                break;
            }
        }
    }
    std::cout << tmpString << std::endl;
    stack.pop();
    dump(stack);
    stack.push(tmp);
}

bool Memory::assert(std::pair<eOperandType, std::string> typeandvalue)
{
    if (_stack.empty()) 
        return (false);
    if (_stack.top()->toString().compare(0, typeandvalue.second.length() ,typeandvalue.second) == 0 ||
        _stack.top()->getType() == typeandvalue.first)
        return (true);
    return (false);
}

bool Memory::store(std::pair<eOperandType, std::string> typeandvalue)
{
    if (_stack.empty() || stoi(typeandvalue.second) > 15)
        return (false);
    registers[stoi(typeandvalue.second)].first = _stack.top();
    registers[stoi(typeandvalue.second)].second = typeandvalue.first;
    pop_top();

    return (true);
}

bool Memory::load(std::pair<eOperandType, std::string> typeandvalue)
{
    if (typeandvalue.first == registers[stoi(typeandvalue.second)].second) {
        _stack.push(registers[stoi(typeandvalue.second)].first);
        registers[stoi(typeandvalue.second)].first = nullptr;
        registers[stoi(typeandvalue.second)].second = None;
        return (true);
    }
    return (false);
}

bool Memory::print()
{
    if (_stack.top()->getType() != Int8)
        return (false);
    
    std::cout << (char)stoi(_stack.top()->toString()) << std::endl;
    return (true);
}