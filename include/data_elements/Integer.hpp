#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "MsgCount.h"

// Provides the base integer type, expressed in unsigned units.

// ASN.1 Representation:
// Heading ::= INTEGER (0..65636)

class CInteger
{
public:
    CInteger();
    CInteger(const MsgCount_t& value);
    CInteger(const int& value);
    virtual ~CInteger();

     MsgCount_t get() const;
    void set(const MsgCount_t& value);

private:
    MsgCount_t value_;
};

#endif // INTEGER_HPP
