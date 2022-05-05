#include "../../includes/CPU/cpu.hpp"

Float_c::Float_c(double value) {
    _value = value;
}

std::string Float_c::toString() const
{
    return my_to_string(_value, 8);
}

eOperandType Float_c::getType() const
{
    return Float;
}

IOperand *Float_c::operator+(const IOperand &rhs) const
{
    float res = _value + std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Float_c::operator-(const IOperand &rhs) const
{
    float res =  _value - std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Float_c::operator*(const IOperand &rhs) const
{
    float res = _value * std::stold(rhs.toString());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Float_c::operator/(const IOperand &rhs) const
{
    float res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());
    
    try {
        if (std::stold(rhs.toString().c_str()) != 0) {
            res = _value / std::stold(rhs.toString());
        } else {
            throw std::logic_error("Error: division by 0");
        }
    }  catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Float_c::operator%(const IOperand &rhs) const
{
    float res = 0;
    
    try {
        if (std::stold(rhs.toString()) != 0)
            res = (int)_value % std::stoi(rhs.toString());
        else {
            throw std::logic_error("Error: modulo by 0");
        }
    } catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(Float, my_to_string(res, getBiggestType(getType(), rhs.getType())));
}
