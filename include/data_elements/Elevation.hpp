#ifndef ELEVATION_HPP__
#define ELEVATION_HPP__

// Represents the geographic position above or below 
// the reference ellipsoid (typically WGS-84). 
// The number has a resolution of 1 decimeter and represents 
// an asymmetric range of positive and negative values. 
// Any elevation higher than +6143.9 meters is represented as +61439. 
// Any elevation lower than -409.5 meters is represented as -4095. 
// If the sending device does not know its elevation, 
// it shall encode the Elevation data element with -4096.

// ASN.1 Representation:
// Elevation ::= INTEGER (-4096..61439)
// -- In units of 10 cm steps above or below the reference ellipsoid
// -- Providing a range of -409.5 to + 6143.9 meters
// -- The value -4096 shall be used when Unknown is to be sent

namespace v2x {
namespace element {

class CElevation
{
public:
    static const long elevationUnknown;

    explicit CElevation();
    CElevation(long value);
    CElevation(int value);
    CElevation(double value);
    virtual ~CElevation();

    explicit operator long() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(long value);
    void set(int value);
    void set(double value);

    CElevation& operator = (const CElevation& other);
    bool operator != (const CElevation& left) const {
        return left.value_ == value_;
    }
    bool operator==(const CElevation& left) {
        return left.value_ == value_;
    }

private:
    long value_;
    void validate();
};

} //v2x
} //element

#endif
