// ----------------- Log.h ---------------

#ifndef LOG_H
#define LOG_H

#include <unordered_map>

namespace Hist
{
    /** \enum EInteger
     *  \brief EInteger enumerable. Derived from int (integer).
     * 
     *  Custom enumerable to provide values to Histogram.
     */
    enum EInteger : int
    {
        Zero = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4
    };

    /** \class Logger
     *  \brief Logger class. Interface and storage for EInteger values provided for Histogram.
     * 
     *  Keeps track of values for Histogram class to use.
     */
    class Logger

    {
    public:
        /** \fn Logger
         *  \brief Logger class Constructor.
         * 
         *  Creates Logger class with initialized empty Log.
         */
        Logger();

        /** \fn Logger
         *  \brief Logger class Constructor.
         * 
         *  Creates Logger class based on given std::unordered_map<EInteger, int> object (by value).
         *  @param std::unordered_map<EInteger, int> values
         */
        Logger(std::unordered_map<EInteger, int> &);

        /** \fn addOne
         *  \brief Adds given EInteger value to the log.
         * 
         *  Adds one to Logger values based on given EInteger. 
         *  @param value EInteger
         *  @returns void
         */
        void addOne(EInteger); 

        /** \fn isEmpty
         *  \brief Checks if Logger is empty from values.
         * 
         *  Checks Logger for values, if one or more found, returns true.
         *  @param none
         *  @returns bool
         */
        bool isEmpty() const;

        /** \fn deleteOne
         *  \brief Deletes one occurrence of given EInteger value.
         * 
         *  Subtracts one from given EInteger value occurrences. 
         *  If given value is not found in stored values, no modification happens.
         *  @param value EInteger
         *  @returns void
         */
        void deleteOne(EInteger);

        /** \fn deleteAll
         *  \brief Deletes all values stored in Logger.
         * 
         *  Initialized Logger empty.
         *  @param none
         *  @returns void
         */
        void deleteAll();

        /** \fn getValues
         *  \brief Returns all values stored in Logger.
         * 
         *  Returns all values stored in Logger by copy.
         *  @param none
         *  @returns std::unordered_map<EInteger, int>
         */
        std::unordered_map<EInteger, int> getValues() const;

        virtual ~Logger() = default;

    private:
        std::unordered_map<EInteger, int> values_ = {}; /**< List of EInteger values and their occurrence amount */
    };

}
#endif /* !LOG_H */