/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** CPU.hpp
*/

#pragma once
#include "IOperand.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
// class Memory;

eOperandType getBiggestType(eOperandType type1, eOperandType type2);
int getPrescion(eOperandType type);

template<typename Type> std::string my_to_string(const Type &t, int precision)
{
    std::ostringstream stream;

    stream << std::fixed << std::setprecision(precision) << t;
    return stream.str();
}

class Factory
{
    public:
        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);
        static IOperand *createOperand(eOperandType type , const std::string &value);
        Factory(){}
        ~Factory(){}
};

class Int8_c: public IOperand
{
    public:
        Int8_c(int value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~Int8_c() {};
        
    protected:
        bool orderIsChanged;
        int _value;
    private:
};

class Int16_c: public IOperand
{
    public:
        Int16_c(int value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~Int16_c() {};
        
    protected:
        bool orderIsChanged;
        int _value;
    private:
};

class Int32_c: public IOperand
{
    public:
        Int32_c(int value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~Int32_c() {};
        
    protected:
        bool orderIsChanged;
        int _value;
    private:
};

class Float_c: public IOperand
{
    public:
        Float_c(double value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~Float_c() {};
        
    protected:
        bool orderIsChanged;
        double _value;
    private:
};

class Double_c: public IOperand
{
    public:
        Double_c(long double value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~Double_c() {};
        
    protected:
        bool orderIsChanged;
        long double _value;
    private:
};

class BigDecimal_c: public IOperand
{
    public:
        BigDecimal_c(double value);
        std::string toString() const;
        eOperandType getType() const;
        IOperand *operator+(const IOperand &rhs) const;
        IOperand *operator-(const IOperand &rhs) const;
        IOperand *operator*(const IOperand &rhs) const;
        IOperand *operator/(const IOperand &rhs) const;
        IOperand *operator%(const IOperand &rhs) const;
        ~BigDecimal_c() {};
        
    protected:
        bool orderIsChanged;
        double _value;
    private:
};

class Cpu {
    public:
        bool push_value(IOperand *v);
        bool pop_top();
        void clear();
};