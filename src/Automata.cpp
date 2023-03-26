// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>


Automata::Automata()
{
    cash = 0;
    state = OFF;
}

void Automata::on()
{
    if (state == OFF)
    {
        cash = 0;
        state = WAIT;
        getMenu();
    }
}

void Automata::off()
{
    getChange();
    cash = 0;
    state = OFF;
}

void Automata::coin(unsigned int sum)
{
    if (state == WAIT || state == ACCEPT)
    {
        cash += sum;
        state = ACCEPT;
    }
    else
    {
        cout << "Operation cannot be performed" << endl;
    }
}

void Automata::getMenu()
{
    cout << "Menu:" << endl;
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++)
    {
        cout << i + 1 << ") " << menu[i] << " -  " << prices[i] << endl;
    }
}

STATES Automata::getState()
{
    return state;
}

void Automata::choice(unsigned int num)
{
    if (state == ACCEPT)
    {
        if (0 < num && num <= sizeof(menu) / sizeof(menu[0]))
        {
            num_of_chosen_drink = num - 1;
            state = CHECK;
            check();
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }
    }
    else
    {
    cout << "Operation cannot be performed" << endl;
    }
}

void Automata::cancel()
{
    if (state == ACCEPT || state == CHECK)
    {
        getChange();
        cash = 0;
        state = WAIT;
    }
    else
    {
        cout << "Operation cannot be performed" << endl;
    }
}

void Automata::check()
{
    if (state == CHECK)
    {
        if (cash >= prices[num_of_chosen_drink])
        {
            getChange(prices[num_of_chosen_drink]);
            cook();
        }
        else
        {
            cout << "Insufficient funds" << endl;
            cancel();
        }
    }
}

void Automata::cook()
{
    if (state == CHECK)
    {
        state = COOK;
        cout << "Your " << menu[num_of_chosen_drink] << " is ready" << endl;
        finish();
    }
}

void Automata::finish()
{
    if (state == COOK)
    {
        cash = 0;
        state = WAIT;
    }
}

void Automata::getChange(unsigned int price)
{
    if (cash - price != 0)
    cout << "Take the change: " << cash - price << endl;
}
