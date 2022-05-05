#include "../../includes/CPU/cpu.hpp"

Double_c::Double_c(long double value) {
    _value = value;
}

std::string Double_c::toString() const
{
    return my_to_string(_value, 15);
}

eOperandType Double_c::getType() const
{
    return Double;
}

IOperand *Double_c::operator+(const IOperand &rhs) const
{
    double res = _value + std::stold(rhs.toString().c_str());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Double_c::operator-(const IOperand &rhs) const
{
    double res = _value - std::stold(rhs.toString().c_str());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Double_c::operator*(const IOperand &rhs) const
{
    double res = _value * std::stold(rhs.toString().c_str());
    eOperandType type = getBiggestType(getType(), rhs.getType());

    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Double_c::operator/(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());
    
    try {
        if (std::stold(rhs.toString().c_str()) != 0)
            res = _value / std::stold(rhs.toString().c_str());
        else {
            throw std::logic_error("Error: division by 0");
        }
    }  catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}

IOperand *Double_c::operator%(const IOperand &rhs) const
{
    double res = 0;
    eOperandType type = getBiggestType(getType(), rhs.getType());
    
    try {
        if (std::stof(rhs.toString()) != 0)
            res = (int)_value % std::stoi(rhs.toString());
        else {
            throw std::logic_error("Error: modulo by 0");
        }
    } catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
    return Factory::createOperand(type, my_to_string(res, getPrescion(type)));
}
