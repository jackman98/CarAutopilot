#ifndef ACCELERATION_SET_4_WAY_HPP__
#define ACCELERATION_SET_4_WAY_HPP__

#include "AccelerationSet4Way.h"

// A set of acceleration values in 3 orthogonal directions 
// of the vehicle and with yaw rotation rates, expressed 
// as a structure. The positive longitudinal axis is to 
// the front of the vehicle. The positive lateral axis is 
// to the right side of the vehicle (facing forward). 
// Positive yaw is to the right (clockwise). 
// A positive vertical "z" axis is downward with the zero 
// point at the bottom of the vehicle's tires. 
// The frame of reference and axis of rotation used shall 
// be accordance with that defined in Section 11 of this standard.

// ASN.1 Representation:
// AccelerationSet4Way ::= SEQUENCE {
//     long Acceleration, -- Along the Vehicle Longitudinal axis
//     lat Acceleration, -- Along the Vehicle Lateral axis
//     vert VerticalAcceleration, -- Along the Vehicle Vertical axis
//     yaw YawRate
// }

class CAccelerationSet4Way 
{
public:
    CAccelerationSet4Way();
    CAccelerationSet4Way(const AccelerationSet4Way_t& value);
    virtual ~CAccelerationSet4Way();

    const AccelerationSet4Way_t get() const;
    void set(const AccelerationSet4Way_t& value);

    //TODO(mykhaylo.korobov) - add getters/setters for elements - long, lat, ver, yaw

private:
    AccelerationSet4Way_t value_;
};

#endif