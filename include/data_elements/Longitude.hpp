#ifndef LONGITUDE_HPP__
#define LONGITUDE_HPP__

// The geographic longitude of an object, expressed in 1/10th 
// integer microdegrees, as a 32-bit value, and with reference 
// to the horizontal datum then in use. The value 1800000001 
// shall be used when unavailable.

// ASN.1 Representation:
// Longitude ::= INTEGER (-1799999999..1800000001) 
// -- LSB = 1/10 micro degree 
// -- Providing a range of plus-minus 180 degrees

namespace v2x {
namespace element {

class CLongitude
{
public:
    explicit CLongitude();
    CLongitude(const long& value);
    CLongitude(const int& value);
    CLongitude(const double& value);
    virtual ~CLongitude();

    explicit operator long() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(const long& value);
    void set(const int& value);
    void set(const double& value);

    CLongitude& operator = (const CLongitude& other);
    bool operator != (const CLongitude& left) const {
        return left.value_ == value_;
    }
    bool operator==(const CLongitude& left) const {
        return left.value_ == value_;
    }


private:
    long value_;
    void validate();
};

} //v2x
} //element

#endif
