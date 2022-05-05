/*
** EPITECH PROJECT, 2021
** B-SYN-400-REN-4-1-abstractVM-antony.crimi
** File description:
** IO.cpp
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "../../includes/Chipset/chipset.hpp"
#include "IOperand.hpp"

void instructions_sequencer(std::vector<std::string> prog);

std::string delspaces(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        //std::cout << "The ASCII value of " << str[i] << " is " << int(str[i]) << std::endl;
        //std::cout << "str[i] = " << str[i] << std::endl;
        if (str[i] == ' ' || str[i] == '\t') {
            if (str[i+1] == ' ' || str[i+1] == '\t' || str[i+1] == '\n') {
                str.erase(str.begin()+i);
                i--;
            }
        }
    }
    if (str[0] == ' ' && str[1] != '\n')
        str.erase(str.begin());
    return str;
}

std::vector<std::string> parsing(std::vector<std::string> str)
{
    size_t buf = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        buf = str[i].find(';');
        if (buf != std::string::npos)
            str[i].erase(str[i].begin()+buf, str[i].end());
        str[i] = delspaces(str[i]);
    }
    return str;
}

std::vector<std::string> fillVectorFromPath(const char *path)
{
    std::ifstream MyReadFile(path);
    std::string buff;
    std::vector<std::string> res;

    while (getline(MyReadFile, buff)) {
        if (buff != "" && buff[0] != ';')
            res.push_back(buff);
    }
    MyReadFile.close();
    return res;
}

void oneArg(const char *path)
{
    std::vector<std::string> pars = fillVectorFromPath(path);
    try
    {
        if (pars.empty())
            throw std::logic_error("Error: there is nothing");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    pars = parsing(pars);
    instructions_sequencer(pars);
}

void twoArg(void)
{
    std::vector<std::string> input;
    std::string myCommand;

    while (std::find(input.begin(), input.end(), ";;") == input.end()) {
        std::getline(std::cin, myCommand);
        if (myCommand != "") 
            input.push_back(myCommand);
        if (myCommand[0] == ';' && myCommand[1] != ';')
            input.pop_back();
        if ((myCommand[0] == ' ' && myCommand[1] == '\0') || (myCommand[0] == '\t' && myCommand[1] == '\0'))
            input.pop_back();
    }
    input.pop_back();
    try
    {
        if (input.empty())
            throw std::logic_error("Error: there is nothing");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    input = parsing(input);
    instructions_sequencer(input);
}