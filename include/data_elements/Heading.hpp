#ifndef HEADING_HPP
#define HEADING_HPP

#include "Heading.h"

// Provides the current heading of the sending device, 
// expressed in unsigned units of 0.0125 degrees from 
// North such that 28799 such degrees represent 359.9875 degrees. 
// North shall be defined as the axis prescribed 
// by the WGS-84 coordinate system and its reference ellipsoid. 
// Headings "to the east" are defined as the positive direction. 
// A value of 28800 shall be used when unavailable. 
// This element indicates the direction of motion of the device. 
// When the sending device is stopped and the trajectory (path) 
// over which it traveled to reach that location is well known, 
// the past heading may be used.

// ASN.1 Representation:
// Heading ::= INTEGER (0..28800) 
//   -- LSB of 0.0125 degrees 
//   -- A range of 0 to 359.9875 degrees

class CHeading
{
public:
    explicit CHeading();
    CHeading(const Heading_t& value);
    CHeading(const int& value);
    CHeading(const double& value);
    virtual ~CHeading();

    explicit operator Heading_t() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(const Heading_t& value);
    void set(const int& value);
    void set(const double& value);

private:
    Heading_t value_;
    void validate();
};

#endif
