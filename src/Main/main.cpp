/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** Main.cpp
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include "../../includes/Chipset/chipset.hpp"
#include "IOperand.hpp"
#include "../../includes/IO/io.hpp"

bool file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void error_handling(int ac, char **av)
{    
    try {
        if (ac > 2)
            throw std::logic_error("Error: too much arguments");
        
        if (ac == 2 && !file_exist(av[1]))
            throw std::logic_error("Error: File does not exist");
    }
    catch (const std::exception& msg) {
        std::cerr << msg.what() << std::endl;
        exit(84);
    }
}

int main(int ac, char **av)
{
    error_handling(ac, av);
    if (ac == 2)
        oneArg(av[1]);
    else if (ac == 1)
        twoArg();
}