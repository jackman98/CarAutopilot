#ifndef STEERING_WHEEL_ANGLE_HPP__
#define STEERING_WHEEL_ANGLE_HPP__

#include "SteeringWheelAngle.h"

// The angle of the driver’s steering wheel, 
// expressed in a signed (to the right being positive) 
// value with LSB units of 1.5 degrees.

// ASN.1 Representation:
// SteeringWheelAngle ::= INTEGER (-126..127)
//    -- LSB units of 1.5 degrees, a range of -189 to +189 degrees
//    -- +001 = +1.5 deg
//    -- -126 = -189 deg and beyond
//    -- +126 = +189 deg and beyond
//    -- +127 to be used for unavailable

class CSteeringWheelAngle 
{
public:
    CSteeringWheelAngle();
    CSteeringWheelAngle(const SteeringWheelAngle_t& value);
    virtual ~CSteeringWheelAngle();

    SteeringWheelAngle_t get() const;
    void set(const SteeringWheelAngle_t& value);

private:
    SteeringWheelAngle_t value_;
};

#endif
