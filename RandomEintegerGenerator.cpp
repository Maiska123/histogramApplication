#include <iostream>
#include <random>

#include "RandomEintegerGenerator.h"
#include "HistogramBase.h"

RandomEintegerGenerator::RandomEintegerGenerator(){};

Hist::EInteger RandomEintegerGenerator::operator()() const
{
    // for the seed value
    std::random_device rd;

    // mersenne_twister_engine with seed
    std::mt19937 gen(rd());

    // hardcoded value in between two int's (min, max)
    std::uniform_int_distribution<> distribution(0, 4);

    return static_cast<Hist::EInteger>(distribution(gen));
};
