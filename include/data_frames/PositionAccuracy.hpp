#ifndef POSITION_ACCURACY_HPP__
#define POSITION_ACCURACY_HPP__

#include "PositionAccuracy.h"

// The DF_PositionalAccuracy data frame consists of
// various parameters of quality used to model the
// accuracy of the positional determination with respect
// to each given axis.

// ASN.1 Representation:
// PositionalAccuracy ::= SEQUENCE {
//   -- NMEA-183 values expressed in strict ASN form
//   semiMajor SemiMajorAxisAccuracy,
//   semiMinor SemiMinorAxisAccuracy,
//   orientation SemiMajorAxisOrientation
// }

class CPositionAccuracy 
{
public:
    CPositionAccuracy();
    CPositionAccuracy(const PositionAccuracy_t& value);
    virtual ~CPositionAccuracy();

    const PositionAccuracy_t get() const;
    void set(const PositionAccuracy_t& value);

    CPositionAccuracy& operator=(const PositionAccuracy_t& rhs);

private:
    PositionAccuracy_t value_;

};

#endif