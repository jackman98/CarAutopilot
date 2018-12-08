#ifndef TRANSMISSION_STATE_HPP__
#define TRANSMISSION_STATE_HPP__

#include <asn_src/TransmissionState.h>

// used to provide the current state of the vehicle transmission.
// ASN.1 Representation:
// TransmissionState ::= ENUMERATED {
//   neutral (0), -- Neutral
//   park (1), -- Park
//   forwardGears (2), -- Forward gears
//   reverseGears (3), -- Reverse gears
//   reserved1 (4),
//   reserved2 (5),
//   reserved3 (6),
//   unavailable (7) -- not-equipped or unavailable value,
//   -- Any related speed is relative to the vehicle reference frame used
// }

class CTransmissionState 
{
public:
    CTransmissionState();
    CTransmissionState(const TransmissionState_t& value);
    virtual ~CTransmissionState();

    TransmissionState_t get() const;
    void set(const TransmissionState_t& value);

private:
    TransmissionState_t value_;
};

#endif