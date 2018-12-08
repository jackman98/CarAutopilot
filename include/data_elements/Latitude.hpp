#ifndef LATITUDE_HPP__
#define LATITUDE_HPP__

// The geographic latitude of an object, expressed in 1/10th 
// integer microdegrees, as a 31 bit value, and with reference 
// to the horizontal datum then in use. The value 900000001 
// shall be used when unavailable.

// ASN.1 Representation
// Latitude ::= INTEGER (-900000000..900000001) 
// -- LSB = 1/10 micro degree 
// -- Providing a range of plus-minus 90 degrees

namespace v2x {
namespace element {

class CLatitude
{
public:
    explicit CLatitude();
    CLatitude(const long& value);
    CLatitude(const int& value);
    CLatitude(const double& value);
    virtual ~CLatitude();

    explicit operator long() const;
    explicit operator int() const;
    explicit operator double() const;

    void set(const long& value);
    void set(const int& value);
    void set(const double& value);

    CLatitude& operator = (const CLatitude& other);
    bool operator != (const CLatitude& left) const {
        return left.value_ == value_;
    }
    bool operator==(const CLatitude& left) {
        return left.value_ == value_;
    }


private:
    long value_;
    void validate();
};

} /* v2x */
} /* element */

#endif
