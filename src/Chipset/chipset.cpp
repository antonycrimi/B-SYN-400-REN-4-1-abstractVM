/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** Chipset.cpp
*/

#include <string>
#include <iostream>
#include "../../includes/Chipset/chipset.hpp"

#define MAX_INT8_VALUE 127
#define MIN_INT8_VALUE -127

#define MAX_INT16_VALUE 32768
#define MIN_INT16_VALUE -32768

#define MAX_INT32_VALUE 2147483648
#define MIN_INT32_VALUE -2147483648

#define MAX_FLOAT_VALUE 340282346638528859811704183484516925440.0000000000000000
#define MIN_FLOAT_VALUE -340282346638528859811704183484516925440.0000000000000000

#define MAX_DOUBLE_VALUE 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
#define MIN_DOUBLE_VALUE -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000

instructions check_instr(const std::string& str)
{
    try {
        for (auto &it : instruct_tab) {
            if (it.first == str)
                return (it.second);
        }
        throw std::logic_error(str);
    }
    catch (const std::exception& msg) {
        std::cerr << "Error: '" << msg.what() << "' unknown command" << std::endl;
        exit(84);
    }
}

eOperandType getType(const std::string& type)
{
    try
    {
        if (type == "int8") return Int8;
        else if (type == "int16") return Int16;
        else if (type == "int32") return Int32;
        else if (type == "float") return Float;
        else if (type == "double") return Double;
        else if (type == "bigdecimal") return BigDecimal;
        else throw std::logic_error(type);
    }
    catch(const std::exception& msg)
    {
        std::cerr << "Error: '" << msg.what() << "' unknown type" << std::endl;
        exit(84);
    }
}

int check_overflow(std::pair<eOperandType, std::string> typeandvalue)
{
    try {
        if (typeandvalue.first == Int8) 
        {
            if (MAX_INT8_VALUE - stoi(typeandvalue.second) >= 0)
                return 0;
            else
                throw std::logic_error("Error: value overflow on int8");
        }
        if (typeandvalue.first == Int16)
        {
            if (MAX_INT16_VALUE - stoi(typeandvalue.second) >= 0)
                return 0;
            else
                throw std::logic_error("Error: value overflow on int16");
        }
        if (typeandvalue.first == Int32)
        {
            if (MAX_INT32_VALUE - stoi(typeandvalue.second) >= 0)
                return 0;
            else
                throw std::logic_error("Error: value overflow on int32");
        }
        if (typeandvalue.first == Int32)
        {
            if (MAX_FLOAT_VALUE - stoi(typeandvalue.second) >= 0)
                return 0;
            else
                throw std::logic_error("Error: value overflow on float");
        }
        if (typeandvalue.first == Int32)
        {
            if (MAX_DOUBLE_VALUE - stoi(typeandvalue.second) >= 0)
                return 0;
            else
                throw std::logic_error("Error: value overflow on double");
        }
    }
    catch(const std::exception& msg)
    {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return 0;
}

int check_underflow(std::pair<eOperandType, std::string> typeandvalue)
{
    try {
        if (typeandvalue.first == Int8) 
        {
            if (MIN_INT8_VALUE - stoi(typeandvalue.second) <= 0)
                return 0;
            else
                throw std::logic_error("Error: value underflow on int8");
        }
        if (typeandvalue.first == Int16)
        {
            if (MIN_INT16_VALUE - stoi(typeandvalue.second) <= 0)
                return 0;
            else
                throw std::logic_error("Error: value underflow on int16");
        }
        if (typeandvalue.first == Int32)
        {
            if (MIN_INT32_VALUE - stoi(typeandvalue.second) <= 0)
                return 0;
            else
                throw std::logic_error("Error: value underflow on int32");
        }
        if (typeandvalue.first == Int32)
        {
            if (MIN_FLOAT_VALUE - stoi(typeandvalue.second) <= 0)
                return 0;
            else
                throw std::logic_error("Error: value underflow on float");
        }
        if (typeandvalue.first == Int32)
        {
            if (MIN_DOUBLE_VALUE - stoi(typeandvalue.second) <= 0)
                return 0;
            else
                throw std::logic_error("Error: value underflow on double");
        }
    }
    catch(const std::exception& msg)
    {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return 0;
}

std::size_t finder(std::string prog, const char *character)
{
    return prog.find(character);
}

std::pair<eOperandType, std::string> check_type(std::string value)
{
    std::size_t delim;
    std::size_t buffer;
    std::string type;
    std::string newvalue;
    std::pair<eOperandType, std::string> typeandvalue;

    try {
        if (finder(value, "(") == std::string::npos || finder(value, ")") == std::string::npos)
            throw std::logic_error("Error: a value is needed");
    }
    catch(const std::exception& msg)
    {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    delim = finder(value, "(");
    buffer = finder(value, ")");
    try
    {
        if (buffer - delim == 1)
            throw std::logic_error("Error: a value is needed");
    }
    catch(const std::exception& msg)
    {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    type = value.substr(0, delim);
    newvalue = value.substr(delim + 1, (buffer-1)-delim);
    try
    {
        for (size_t i = 0; i < newvalue.size(); i++)
        {
            if (newvalue[i] != '-' && newvalue[i] != '.' && (newvalue[i] < '0' || newvalue[i] > '9'))
                throw std::logic_error("Error: the value must be a number");
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    
    typeandvalue = {getType(type), newvalue};
    return typeandvalue;
}

int getPrescion(eOperandType type)
{
    int precision = 0;

    switch (type) {
        case Int8:
            precision = 3;
            break;
        case Int16:
            precision = 4;
            break;
        case Int32:
            precision = 5;
            break;
        case Float:
            precision = 7;
            break;
        case Double:
            precision = 15;
            break;
        case BigDecimal:
            precision = 200;
            break;
        case None:
            break;
    }
    return precision;
}

void instructions_sequencer(std::vector<std::string> prog)
{
    std::pair<eOperandType, std::string> typeandvalue;
    std::string value;
    Memory *mem = new Memory();
    eOperandType tmpType;
    std::string tmpValue;
    IOperand *tmp;

    for (std::size_t i = 0; i < prog.size(); i++) {
        std::size_t delim = finder(prog[i], " ");
        std::string instr = prog[i].substr(0, delim);
        instructions type = check_instr(instr);
        switch (type) {
            case comment_e:
                break;
            case push_e:
                value = prog[i].substr(delim + 1, delim - prog[i].size());
                typeandvalue = check_type(value);
                check_overflow(typeandvalue);
                check_underflow(typeandvalue);
                mem->push_value(Factory::createOperand(typeandvalue.first, typeandvalue.second));
                break;
            case pop_e:
                try
                {
                    if (!mem->pop_top())
                        throw std::logic_error("Error: the stack is empty");
                }
                catch(const std::exception& e)
                {
                    std::cerr << "Line " << i + 1 << " : " << e.what() << std::endl;
                    exit(84);
                }
                break;
            case clear_e:
                mem->clear();
                break;
            case dup_e:
                try
                {
                    if (mem->_stack.empty())
                        throw std::logic_error("Error: cannot duplicate an empty stack");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case swap_e:
                try {
                    if (!mem->swap())
                        throw std::logic_error("Error: not enough values to swap");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case dump_e:
                mem->dump(mem->_stack);
                break;
            case assert_e:
                value = prog[i].substr(delim + 1, delim - prog[i].size());
                typeandvalue = check_type(value);
                check_overflow(typeandvalue);
                try {
                    if (!mem->assert(typeandvalue))
                        throw std::logic_error("Error: the values aren't equal");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case add_e:
                try {
                    if (mem->_stack.size() < 2)
                        throw std::logic_error("Error: you need two values");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                tmpType = mem->_stack.top()->getType();
                tmpValue = mem->_stack.top()->toString();
                tmp = Factory::createOperand(tmpType, tmpValue);
                mem->swap();
                mem->push_value(mem->_stack.top()->operator+(*tmp));
                mem->swap();
                mem->pop_top();
                mem->swap();
                mem->pop_top();
                break;
            case sub_e:
                try {
                    if (mem->_stack.size() < 2)
                        throw std::logic_error("Error: you need two values");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                tmpType = mem->_stack.top()->getType();
                tmpValue = mem->_stack.top()->toString();
                tmp = Factory::createOperand(tmpType, tmpValue);
                mem->swap();
                mem->push_value(mem->_stack.top()->operator-(*tmp));
                mem->swap();
                mem->pop_top();
                mem->swap();
                mem->pop_top();
                break;
            case mul_e:
                try {
                    if (mem->_stack.size() < 2)
                        throw std::logic_error("Error: you need two values");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                tmpType = mem->_stack.top()->getType();
                tmpValue = mem->_stack.top()->toString();
                tmp = Factory::createOperand(tmpType, tmpValue);
                mem->swap();
                mem->push_value(mem->_stack.top()->operator*(*tmp));
                mem->swap();
                mem->pop_top();
                mem->swap();
                mem->pop_top();
                break;
            case div_e:
                try {
                    if (mem->_stack.size() < 2)
                        throw std::logic_error("Error: you need two values");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                tmpType = mem->_stack.top()->getType();
                tmpValue = mem->_stack.top()->toString();
                tmp = Factory::createOperand(tmpType, tmpValue);
                mem->swap();
                mem->push_value(mem->_stack.top()->operator/(*tmp));
                mem->swap();
                mem->pop_top();
                mem->swap();
                mem->pop_top();
                break;
            case mod_e:
                tmpType = mem->_stack.top()->getType();
                tmpValue = mem->_stack.top()->toString();
                tmp = Factory::createOperand(tmpType, tmpValue);
                try {
                    if (mem->_stack.empty())
                        throw std::logic_error("Error: you need two values");
                    if (mem->_stack.size() < 2)
                        throw std::logic_error("Error: you need two values");
                    if (tmpType == Float || tmpType == Double || tmpType == BigDecimal)
                        throw std::logic_error("Error: must use an integer");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                mem->swap();
                mem->push_value(mem->_stack.top()->operator%(*tmp));
                mem->swap();
                mem->pop_top();
                mem->swap();
                mem->pop_top();
                break;
            case load_e:
                value = prog[i].substr(delim + 1, delim - prog[i].size());
                typeandvalue = check_type(value);
                check_overflow(typeandvalue);
                try {
                    if (!mem->load(typeandvalue))
                        throw std::logic_error("Error: you can only print 8-bit integers");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case store_e:
                value = prog[i].substr(delim + 1, delim - prog[i].size());
                typeandvalue = check_type(value);
                check_overflow(typeandvalue);
                try {
                    if (!mem->store(typeandvalue))
                        throw std::logic_error("Error: you can only print 8-bit integers");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case print_e:
                try {
                    if (mem->_stack.empty())
                        throw std::logic_error("Error: you can't print an empty stack");
                    if (!mem->print())
                        throw std::logic_error("Error: you can only print 8-bit integers");
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << std::endl;
                    exit(84);
                }
                break;
            case exit_e:
                exit(0);
                return;
        }
    }
    try {
        if (prog[prog.size() - 1] != "exit")
            throw std::logic_error("Error: the program does not have an exit instruction");
    }
    catch(const std::exception& msg)
    {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    
}