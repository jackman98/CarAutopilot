#ifndef BRAKE_SYSTEM_STATUS_HPP
#define BRAKE_SYSTEM_STATUS_HPP

#include <vector>
#include "BrakeSystemStatus.h"
#include <data_elements/CBitString.hpp>

// Conveys a variety of information about 
// the current brake and system control activity of the vehicle. 
// The structure consist of a sequence of items 
// which provide status flags for any active brakes per wheel,
// the traction control system, the anti-lock brake system,
// the stability control system, the brake boost system,
// and the auxiliary brake system.

// ASN.1 Representation:
// BrakeSystemStatus ::= SEQUENCE {
//    wheelBrakes BrakeAppliedStatus,
//    traction TractionControlStatus,
//    abs AntiLockBrakeStatus,
//    scs StabilityControlStatus,
//    brakeBoost BrakeBoostApplied,
//    auxBrakes AuxiliaryBrakeStatus
// }

class CBrakeSystemStatus 
{
public:    
    CBrakeSystemStatus();
    virtual ~CBrakeSystemStatus();

    v2x::element::CBitStringCorrect getBrakeAppliedStatus() const;
    long getTractionControlStatus() const;
    long getAntiLockBrakeStatus() const;
    long getStabilityControlStatus() const;
    long getBrakeBoostApplied() const;
    long getAuxiliaryBrakeStatus() const;

    void setBrakeAppliedStatus(const v2x::element::CBitStringCorrect & value);
    void setTractionControlStatus(long value);
    void setAntiLockBrakeStatus(long value);
    void setStabilityControlStatus(long value);
    void setBrakeBoostApplied(long value);
    void setAuxiliaryBrakeStatus(long value);

private:
    BrakeSystemStatus_t value_;
    v2x::element::CBitStringCorrect brakeAppliedStatus_;
    long tractionControlStatus_;
    long antiLockBrakeStatus_;
    long stabilityControlStatus_;
    long brakeBoostApplied_;
    long auxiliaryBrakeStatus_;
};

#endif
