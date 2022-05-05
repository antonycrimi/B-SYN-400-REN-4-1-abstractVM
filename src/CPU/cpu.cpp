/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** CPU.cpp
*/
#include "../../includes/CPU/cpu.hpp"

eOperandType getBiggestType(eOperandType type1, eOperandType type2)
{
    int op1Size = 0;
    int op2Size = 0;

    switch (type1) {
        case Int8:
            op1Size = 1;
            break;
        case Int16:
            op1Size = 2;
            break;
        case Int32:
            op1Size = 3;
            break;
        case Float:
            op1Size = 4;
            break;
        case Double:
            op1Size = 5;
            break;
        case BigDecimal:
            op1Size = 6;
            break;
        case None:
            break;
    }
    switch (type2) {
        case Int8:
            op2Size = 1;
            break;
        case Int16:
            op2Size = 2;
            break;
        case Int32:
            op2Size = 3;
            break;
        case Float:
            op2Size = 4;
            break;
        case Double:
            op2Size = 5;
            break;
        case BigDecimal:
            op2Size = 6;
            break;
        case None:
            break;
    }
    if (op2Size < op1Size)
        return type1;
    else
        return type2;
}

IOperand *Factory::createInt16(const std::string &value)
{
    IOperand *a = new Int16_c(std::stoi(value));
    return a;
}

IOperand *Factory::createInt8(const std::string &value)
{
    IOperand *a = new Int8_c(std::stoi(value));
    return a;
}

IOperand *Factory::createInt32(const std::string &value)
{
    IOperand *a = new Int32_c(std::stoi(value));
    return a;
}

IOperand *Factory::createFloat(const std::string &value)
{
    IOperand *a = new Float_c(std::stold(value));
    return a;
}

IOperand *Factory::createDouble(const std::string &value)
{
    IOperand *a = new Double_c(std::stold(value));
    return a;
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    IOperand *a = new BigDecimal_c(std::stod(value));
    return a;
}

IOperand *Factory::createOperand(eOperandType type , const std::string &value)
{
    Factory res;
    
    switch (type) {
        case Int8 :
            return res.createInt8(value);
        case Int16 :
            return res.createInt16(value);
        case Int32 :
            return res.createInt32(value);
        case Float :
            return res.createFloat(value);
        case Double :
            return res.createDouble(value);
        case BigDecimal :
            return res.createBigDecimal(value);
        case None :
            return nullptr;
    }
    return nullptr;
}