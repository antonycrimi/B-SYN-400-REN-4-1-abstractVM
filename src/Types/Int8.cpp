#include "../../includes/CPU/cpu.hpp"

Int8_c::Int8_c(int value) {
    _value = value;
}

std::string Int8_c::toString() const
{
    return my_to_string(_value, 2);
}

eOperandType Int8_c::getType() const
{
    return Int8;
}

IOperand *Int8_c::operator+(const IOperand &rhs) const
{
    double res = _value + std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int8_c::operator-(const IOperand &rhs) const
{
    double res = _value - std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int8_c::operator*(const IOperand &rhs) const
{
    double res = _value * std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int8_c::operator/(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());

    try {
        if (std::stof(rhs.toString()) != 0) {
            res = _value / std::stold(rhs.toString());
        } else {
            throw std::logic_error("Error: division by 0");
        }
    } catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Int8_c::operator%(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());

    try {
        if (std::stof(rhs.toString()) != 0)
            res = _value % std::stoi(rhs.toString().c_str());
        else {
            throw std::logic_error("Error: modulo by 0");
        }
    } catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}
