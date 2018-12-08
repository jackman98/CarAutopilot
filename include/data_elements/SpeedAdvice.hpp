#ifndef __SPEED_ADVICE_HPP__
#define __SPEED_ADVICE_HPP__

#include "SpeedAdvice.h"

/*
 * This data element represents the recommended velocity of an object,
 * typically a vehicle speed along a roadway, expressed in unsigned units
 * of 0.1 meters per second.
 *
 * SpeedAdvice ::= INTEGER (0..500)
 * -- LSB units are 0.1 m/s^2
 * -- the value 499 shall be used for values at or greater than 49.9 m/s
 * -- the value 500 shall be used to indicate that speed is unavailable
 */

namespace v2x {
namespace element {

class CSpeedAdvice 
{
public:
    explicit CSpeedAdvice();
    CSpeedAdvice(const SpeedAdvice_t& value);
    CSpeedAdvice(const int& value);
    CSpeedAdvice(const double& value);
    virtual ~CSpeedAdvice();

    explicit operator SpeedAdvice_t() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(const SpeedAdvice_t& value);
    void set(const int& value);
    void set(const double& value);

private:
    SpeedAdvice_t value_;
    void validate();
};

} /* v2x */
} /* element */
#endif /* __SPEED_ADVICE_HPP__ */
