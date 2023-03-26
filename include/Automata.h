// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>


enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
    unsigned int cash;
    std::string menu[6] = {"americano",
                           "cappuccino",
                           "latte",
                           "espresso",
                           "hot chocolate",
                           "tea"};
    unsigned int prices[6] = {100, 90, 80, 90, 80, 40};
    STATES state;
    unsigned int num_of_chosen_drink;

 public:
    Automata();
    void on();
    void off();
    void coin(unsigned int sum);
    void getMenu();
    STATES getState();
    void choice(unsigned int num);
    void cancel();

 private:
    void check();
    void cook();
    void finish();
    void getChange(unsigned int price = 0);
};
