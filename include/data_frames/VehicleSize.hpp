#ifndef VEHICLE_SIZE_HPP__
#define VEHICLE_SIZE_HPP__

#include "VehicleSize.h"

// Representing the vehicle length and vehicle width 
// in a single data concept.

// ASN.1 Representation:
// VehicleSize ::= SEQUENCE {
//    width VehicleWidth,
//    length VehicleLength
// }

class CVehicleSize 
{
public:
    CVehicleSize();
    CVehicleSize(const VehicleSize_t& value);
    CVehicleSize(const long width, const long length);
    virtual ~CVehicleSize();

    const VehicleSize_t get() const;
    void set(const VehicleSize_t& value);

    void setWidth(const long width);
    long getWidth();

    void setLength(const long length);
    long getLength();

private:
    VehicleSize_t value_;
};

#endif
