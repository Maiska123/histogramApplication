#include "Log.h"
#include "Histogram.h"

#include <iostream>

Hist::Logger::Logger()
{
    values_ = {};
    std::cout << "Empty Logger initialized." << std::endl;
};

Hist::Logger::Logger(std::unordered_map<Hist::EInteger, int> &values)
    : values_(values) {}

void Hist::Logger::addOne(Hist::EInteger value)
{
    if (auto search = values_.find(value); search != values_.end())
    {
        if (search->second < INT_MAX)
            search->second++;
    }
    else
    {
        values_.insert({value, 1});
    }
};

bool Hist::Logger::isEmpty() const
{
    if (values_.size() == 0)
        return true;
    else
        return false;
}

void Hist::Logger::deleteOne(Hist::EInteger value)
{
    if (auto search = values_.find(value); search != values_.end())
    {
        if (!(search->second <= 0))
        {
            search->second--;
        }
    }
};

void Hist::Logger::deleteAll()
{
    values_.clear();
};

std::unordered_map<Hist::EInteger, int> Hist::Logger::getValues() const
{
    return values_;
};
