// ----------------- RandomEintegerGenerator.h ---------------

#ifndef RANDOMEINTEGERGENERATOR_H
#define RANDOMEINTEGERGENERATOR_H

#include "Log.h"
#include "Histogram.h"

/** \class RandomEintegerGenerator
 *  \brief RandomEintegerGenerator class. Used to generate random EInteger values.
 * 
 *  Once initialized, by calling class operator()(), returns always random value between 0 to 4 (incl.)
 */
class RandomEintegerGenerator
    : public Hist::RandomEintegerGeneratorBase
{
public:
    /** \fn RandomEintegerGenerator
     *  \brief RandomEintegerGenerator class Constructor.
     * 
     *  Default class constructor.
     *  @param none
     *  @returns void
     */
    RandomEintegerGenerator() = default;

    /** \fn operator()()
     *  \brief Returns random EInteger value from 0 to 4 (incl.).
     * 
     *  Returns EInteger value base on std::mersenne_twister_engine with seed generated by std::random_device
     *  and then std::uniform_int_distribution to validate return value to match integer between 0 to 4 (incl.)
     *  which is then statically casted to Hist::EInteger value
     *  @param none
     *  @returns Hist::EInteger
     */
    Hist::EInteger operator()() const;

    virtual ~RandomEintegerGenerator() = default;
};

#endif /* !RANDOMEINTEGERGENERATOR_H */