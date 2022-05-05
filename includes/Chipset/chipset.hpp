/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-antony.crimi
** File description:
** Chipset.hpp
*/

#ifndef CHIPSET_HPP_
#define CHIPSET_HPP_
#include "../../includes/CPU/cpu.hpp"
#include "../../includes/Memory/memory.hpp"
#include <map>
#include <string>

#define INT8 1
#define INT16 2
#define INT32 3
#define FLOAT 4
#define DOUBLE 5
#define BIGDECIMAL 6

enum instructions {
    comment_e,
    push_e,
    pop_e,
    clear_e,
    dup_e,
    swap_e,
    dump_e,
    assert_e,
    add_e,
    sub_e,
    mul_e,
    div_e,
    mod_e,
    load_e,
    store_e,
    print_e,
    exit_e
};

static const std::map<std::string, instructions> instruct_tab {
    {"comment", comment_e},
    {"push", push_e},
    {"pop", pop_e},
    {"clear", clear_e},
    {"dup", dup_e},
    {"swap", swap_e},
    {"dump", dump_e},
    {"assert", assert_e},
    {"add", add_e},
    {"sub", sub_e},
    {"mul", mul_e},
    {"div", div_e},
    {"mod", mod_e},
    {"load", load_e},
    {"store", store_e},
    {"print", print_e},
    {"exit", exit_e}
};

class chipset {
    public:
        void instructions_sequencer(std::vector<std::string>);
};

#endif