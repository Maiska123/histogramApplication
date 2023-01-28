// ----------------- Histogram.h ---------------

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "HistogramBase.h"

/** \namespace Hist
 *  \brief Namespace to hold everything Histogram related.
 * 
 *  Contents:
 *      class Histogram,
 *      class HistogramBase,
 *      class Logger,
 *      enum EInteger,
 *      
 *  Not related:
 *      class RandomEintegerGeneratorBase
 */
namespace Hist
{

    /** \class Histogram
     *  \brief Histogram class. Derived from HistogramBase.
     * 
     *  Keeps track of values of Logger type.
     */
    class Histogram
        : public Hist::HistogramBase
    {
    public:
        Histogram() = delete;
        
        /** \fn Histogram
         *  \brief Histogram class Constructor. Derived from HistogramBase.
         * 
         *  Creates HistogramBase class based on given Logger class.
         *  @param log std::unique_ptr<Logger> 
         */
        Histogram(std::unique_ptr<Logger> log)
            : Hist::HistogramBase(std::move(log)){};

        /** \fn Histogram
         *  \brief Histogram class Constructor. Derived from HistogramBase.
         * 
         *  Creates HistogramBase class based on given Histogram class (by value).
         *  @param &base const Histogram
         */
        Histogram(const Histogram &base)
            : Hist::HistogramBase(base){};

        /** \fn Histogram
         *  \brief Histogram class Constructor. Derived from HistogramBase.
         * 
         *  Creates HistogramBase class based on given Logger class.
         *  @param &&base Histogram 
         */
        Histogram(Histogram &&base)
            : Hist::HistogramBase(base){};

        virtual ~Histogram() = default;

        /** \fn add
         *  \brief Adds given EInteger value to the log.
         * 
         *  Value is added to histograms protected Logger-class.
         *  @param value EInteger
         *  @returns void
         */
        void add(EInteger);


        /** \fn getMode
         *  \brief Return the value that occurs most often in the dataset.
         *  
         *  (I.e. there exists no other value that occurs more often than the return value)
         *  @param none
         *  @returns EInteger
         */
        EInteger getMode() const;

        /** \fn getMinValue
         *  \brief Return the smallest value in the data set.
         * 
         *  (According to default ordering relation of integer numbers)
         *  @param none
         *  @returns EInteger
         */
        EInteger getMinValue() const;

        
        /** \fn getMaxValue
         *  \brief Return the largest value in the data set.
         * 
         *  (According to default ordering relation of integer numbers)
         *  @param none
         *  @returns EInteger
         */
        EInteger getMaxValue() const;


        /** \fn getAllValues
         *  \brief Return allValues held by Histograms Logger-class.
         * 
         *  @param none
         *  @returns std::unordered_map<Hist::EInteger, int>
         */
        std::unordered_map<Hist::EInteger, int> getAllValues() const;
    };

}
#endif /* !HISTOGRAM_H */