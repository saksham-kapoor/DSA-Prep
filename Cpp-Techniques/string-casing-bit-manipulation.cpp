string s = "aBcDEfGhUyG";

// lowercase to uppercase
for (auto &c : s)
    c &= ~' ';

// uppercase to lowercase
for (auto &c : s)
    c |= ' ';

// vice versa
for (auto &c : s)
    c ^= ' ';