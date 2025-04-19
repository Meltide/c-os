#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <cstring>

using namespace std;

int randint(int min, int max)
{
    mt19937 generator;
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void randchoice(char *in[], int len, char *out)
{
    strcpy(out, in[randint(0, len - 1)]);
}

#endif