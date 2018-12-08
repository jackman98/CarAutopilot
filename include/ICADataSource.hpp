#pragma once

#include "msg/MessageCounter.hpp"
#include "GlobalPrimitives.hpp"
#include "Car.hpp"
#include "data_frames/PathPrediction.hpp"
#include "data_frames/IntersectionReferenceID.hpp"
#include "data_frames/ApproachOrLane.hpp"
#include "data_elements/MinuteOfTheYear.hpp"
#include "data_frames/CVehicleEventFlags.hpp"

namespace v2x {

class ICADataSource {
public:
    virtual  element::CTempId getTempId() const = 0;
    virtual  element::CMinuteOfTheYear getCMinuteOfTheYear() const = 0;
    virtual  Car getBSMCoreData() const = 0;
    //virtual  CPathHistory getCPathHistory() const = 0;
    virtual  frame::CPathPrediction getCPathPrediction() const = 0;
    virtual  frame::CIntersectionReferenceID getCIntersectionReferenceID() const = 0;
    virtual  frame::CApproachOrLane getCApproachOrLane() const = 0;
    virtual  CBrakeSystemStatus getBrakeSystemStatus() const = 0;
    virtual  frame::CVehicleEventFlags getCVehicleEventFlags() const = 0;

    virtual void setTempId(const element::CTempId& tempId) = 0;
    virtual void setCMinuteOfTheYear(const element::CMinuteOfTheYear& minuteOfTheYear) = 0;
    virtual void setBSMCoreData(const Car& car) = 0;
    //virtual void setCPathHistory(const CPathHistory& pathHistory) = 0;
    virtual void setCPathPrediction(const frame::CPathPrediction& pathPrediction) = 0;
    virtual void setCIntersectionReferenceID(const frame::CIntersectionReferenceID& referenceID) = 0;
    virtual void setCApproachOrLane(const frame::CApproachOrLane & approachOrLane) = 0;
    virtual void setCVehicleEventFlags(const frame::CVehicleEventFlags& vehicleEventFlags) = 0;
};
}
