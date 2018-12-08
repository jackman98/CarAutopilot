#ifndef SPEED_HPP__
#define SPEED_HPP__

#include "Speed.h"

// Represents the vehicle speed expressed in unsigned units
// of 0.02 meters per second. A value of 8191 shall be used
// when the speed is unavailable.

// ASN.1 Representation:
// Speed ::= INTEGER (0..8191) -- Units of 0.02 m/s
//          -- The value 8191 indicates that
//          -- speed is unavailable

class CSpeed 
{
public:
    explicit CSpeed();
    CSpeed(const Speed_t& value);
    CSpeed(const int& value);
    CSpeed(const double& value);
    virtual ~CSpeed();

    explicit operator Speed_t() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(const Speed_t& value);
    void set(const int& value);
    void set(const double& value);

private:
    Speed_t value_;
    void validate();
};

#endif
