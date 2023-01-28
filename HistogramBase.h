// ----------------- HistogramBase.h ---------------

#ifndef HISTOGRAMBASE_H
#define HISTOGRAMBASE_H

#include "Log.h"

#include <memory>
namespace Hist
{

    class RandomEintegerGeneratorBase
    {
    public:
        // Returns a pseudo-random EInteger value
        virtual EInteger operator()() const = 0;
    };

    class HistogramBase

    {
    public:
        HistogramBase() = delete;

        HistogramBase(std::unique_ptr<Logger>);

        HistogramBase(const HistogramBase &);

        HistogramBase(HistogramBase &&);

        virtual ~HistogramBase() = default;

        virtual void add(EInteger) = 0;

        // Return the value that occurs most often in the data set (I.e. there exists no other value that occurs more often than the return value)
        virtual EInteger getMode() const = 0;

        // Return the smallest value in the data set, according to default ordering relation of integer numbers
        virtual EInteger getMinValue() const = 0;

        // Return the largest value in the data set
        virtual EInteger getMaxValue() const = 0;

    protected:
        std::unique_ptr<Logger> m_log;
    };

}

#endif /* !HISTOGRAMBASE_H */