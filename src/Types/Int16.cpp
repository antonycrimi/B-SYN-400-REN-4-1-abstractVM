#include "../../includes/CPU/cpu.hpp"

Int16_c::Int16_c(int value) {
    _value = value;
}

std::string Int16_c::toString() const
{
    return std::to_string(_value);
}

eOperandType Int16_c::getType() const
{
    return Int16;
}

IOperand *Int16_c::operator+(const IOperand &rhs) const
{
    double res = _value + std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int16_c::operator-(const IOperand &rhs) const
{
    double res = _value - std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int16_c::operator*(const IOperand &rhs) const
{
    double res = _value * std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int16_c::operator/(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());
    
    try {
        if (atof(rhs.toString().c_str()) != 0)
            res = atof(rhs.toString().c_str()) / _value;
        else 
            throw std::logic_error("Error: division by zero");
    }  catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int16_c::operator%(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());

    try {
        if (std::stof(rhs.toString()) != 0)
            res = _value % std::stoi(rhs.toString());
        else {
            throw std::logic_error("Error: modulo by 0");
        }
    } catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}
