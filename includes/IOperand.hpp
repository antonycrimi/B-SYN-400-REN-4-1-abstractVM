/*
** EPITECH PROJECT, 2021
** operand
** File description:
** interface
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <vector>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal,
    None
};

class IOperand {
    public:
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
        virtual ~IOperand() {};
    protected:
    private:
};
