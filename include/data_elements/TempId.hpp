#ifndef TEMPID_HPP__
#define TEMPID_HPP__

#include "TemporaryID.h"
#include <string>

// This is the 4 octet random device identifier, called the TemporaryID. When used for a mobile OBU device, this value
// will change periodically to ensure the overall anonymity of the vehicle, unlike a typical wireless or wired 802 device ID.
// Because this value is used as a means to identify the local vehicles that are interacting during an encounter, it is used in
// the message set. Other devices, such as infrastructure (RSUs), may have a fixed value for the temporary ID value. See
// also DE_StationID which is used in other deployment regions.

// ASN.1 Representation:
// TemporaryID ::= OCTET STRING (SIZE(4))

namespace v2x {
namespace element {

class CTempId
{
public:
    CTempId();
    CTempId(const TemporaryID_t& value);
    virtual ~CTempId();

    const TemporaryID_t get() const;
    void set(const TemporaryID_t& value);
    std::string toString() const;
    bool operator== (const CTempId& rval);
    bool operator!= (const CTempId& rval);

private:
    TemporaryID_t value_;
};

} /* v2x */
} /* element */
#endif
