// Copyright 2023 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"


TEST(on, test1) {
    Automata A;
    A.on();
    EXPECT_EQ(WAIT, A.getState());
}

TEST(on, test2) {
    Automata A;
    A.on();
    A.coin(1);
    A.on();
    EXPECT_EQ(ACCEPT, A.getState());
}

TEST(off, test3) {
    Automata A;
    EXPECT_EQ(OFF, A.getState());
}

TEST(off, test4) {
    Automata A;
    A.on();
    A.coin(1);
    A.off();
    EXPECT_EQ(OFF, A.getState());
}

TEST(cancel, test5) {
    Automata A;
    A.on();
    A.coin(1);
    A.cancel();
    EXPECT_EQ(WAIT, A.getState());
}

TEST(cancel, test6) {
    Automata A;
    A.on();
    A.coin(1);
    A.choice(1);
    EXPECT_EQ(WAIT, A.getState());
}

TEST(coin, test7) {
    Automata A;
    A.on();
    A.coin(1);
    A.coin(1);
    EXPECT_EQ(ACCEPT, A.getState());
}

TEST(insufficient_funds, test8) {
    Automata A;
    A.on();
    A.coin(10);
    A.choice(4);
    EXPECT_EQ(WAIT, A.getState());
}

TEST(correct_work, test9) {
    Automata A;
    A.on();
    A.coin(10);
    A.cancel();
    A.coin(50);
    A.coin(50);
    A.choice(2);
    EXPECT_EQ(WAIT, A.getState());
}
