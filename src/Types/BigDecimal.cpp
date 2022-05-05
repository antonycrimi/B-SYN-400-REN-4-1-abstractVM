#include "../../includes/CPU/cpu.hpp"

BigDecimal_c::BigDecimal_c(double value) {
    _value = 1;//value;
}

std::string BigDecimal_c::toString() const
{
    if (_value)
        return std::to_string(_value);
    return nullptr;
}

eOperandType BigDecimal_c::getType() const
{
    return BigDecimal;
}

IOperand *BigDecimal_c::operator+(const IOperand &rhs) const
{
    double res = _value + std::stod(rhs.toString());

    return Factory::createOperand(BigDecimal, std::to_string(res));
}

IOperand *BigDecimal_c::operator-(const IOperand &rhs) const
{
    double res = _value - std::stod(rhs.toString());

    return Factory::createOperand(BigDecimal, std::to_string(res));
}

IOperand *BigDecimal_c::operator*(const IOperand &rhs) const
{
    double res = _value * std::stod(rhs.toString().c_str());

    return Factory::createOperand(BigDecimal, std::to_string(res));
}

IOperand *BigDecimal_c::operator/(const IOperand &rhs) const
{
    double res = 0;
    
    try {
        if (std::stod(rhs.toString().c_str()) != 0)
            res = _value / std::stod(rhs.toString().c_str());
        else {
            throw "division by 0";
        }
    }  catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(84);
    }
    return Factory::createOperand(BigDecimal, std::to_string(res));
}

IOperand *BigDecimal_c::operator%(const IOperand &rhs) const
{
    double res = (int)_value % std::stoi(rhs.toString().c_str());

    return Factory::createOperand(BigDecimal, std::to_string(res));
}
