#include "Histogram.h"
#include "HistogramBase.h"

#include <iostream>
#include <stdio.h>

#include <string>
using std::string;

#include <vector>
using std::begin;
using std::end;
using std::vector;

#include <algorithm>
using std::count;
using std::sort;

Hist::HistogramBase::HistogramBase(std::unique_ptr<Logger> log)
    : m_log(std::make_unique<Logger>(*(log)))
{
    std::cout << "Histogram initialized with logger" << std::endl;
};

Hist::HistogramBase::HistogramBase(const HistogramBase &base)
    : m_log(std::make_unique<Logger>(*base.m_log)) {}

Hist::HistogramBase::HistogramBase(HistogramBase &&base)
    : m_log(std::move(base.m_log)){};

void Hist::Histogram::add(Hist::EInteger value)
{
    m_log->addOne(value);
};

// Return the value that occurs most often in the data set
// (I.e. there exists no other value that occurs more often than the return value)
Hist::EInteger Hist::Histogram::getMode() const
{
    Hist::EInteger mostOccurred = Hist::EInteger::Zero;

    if (m_log->isEmpty())
    {
        std::cout << "Histogram is empty!" << std::endl;
        return mostOccurred;
    }
    int lastValue = -1;

    for (auto &[key, value] : m_log->getValues())
    {
        if (lastValue == -1)
        {
            lastValue = value;
            mostOccurred = key;
        }
        if (lastValue < value)
        {
            mostOccurred = key;
            lastValue = value;
        }
    }
    return mostOccurred;
};

Hist::EInteger Hist::Histogram::getMinValue() const
{
    Hist::EInteger minValue = Hist::EInteger::Zero;

    if (m_log->isEmpty())
    {
        std::cout << "Histogram is empty!" << std::endl;
        return minValue;
    }

    int lastValue = -1;

    for (auto &[key, value] : m_log->getValues())
    {
        if (lastValue == -1)
        {
            lastValue = value;
            minValue = key;
        }
        if (minValue > key)
        {
            minValue = key;
            lastValue = value;
        }
    }
    return minValue;
};

Hist::EInteger Hist::Histogram::getMaxValue() const
{
    Hist::EInteger maxValue = Hist::EInteger::Zero;

    if (m_log->isEmpty())
    {
        std::cout << "Histogram is empty!" << std::endl;
        return maxValue;
    }

    int lastValue = -1;

    for (auto &[key, value] : m_log->getValues())
    {
        if (lastValue == -1)
        {
            lastValue = value;
            maxValue = key;
        }
        if (maxValue < key)
        {
            maxValue = key;
            lastValue = value;
        }
    }
    return maxValue;
};

std::unordered_map<Hist::EInteger, int> Hist::Histogram::getAllValues() const
{
    return m_log->getValues();
};