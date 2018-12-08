#pragma once
#include "ICADataSource.hpp"
#include "msg/ICAMessage.hpp"

namespace v2x {

class IntersectionCollisionAvoidance : public ICADataSource{
public:
    IntersectionCollisionAvoidance();
    virtual ~IntersectionCollisionAvoidance();

    virtual  element::CTempId getTempId() const override;
    virtual  element::CMinuteOfTheYear getCMinuteOfTheYear() const override;
    virtual  Car getBSMCoreData() const override;
   // virtual  CPathHistory getCPathHistory() const override;
    virtual  frame::CPathPrediction getCPathPrediction() const override;
    virtual  frame::CIntersectionReferenceID getCIntersectionReferenceID() const override;
    virtual  frame::CApproachOrLane getCApproachOrLane() const override;
    virtual  frame::CVehicleEventFlags getCVehicleEventFlags() const override;
    virtual  CBrakeSystemStatus getBrakeSystemStatus() const override;

    void setTempId(const element::CTempId& tempId) override;
    void setCMinuteOfTheYear(const element::CMinuteOfTheYear& minuteOfTheYear) override;
    void setBSMCoreData(const Car& bsmCoreData) override;//BSMCoreData it's Car
   // void setCPathHistory(const CPathHistory& pathHistory) override;
    void setCPathPrediction(const frame::CPathPrediction& pathPrediction) override;
    void setCIntersectionReferenceID(const frame::CIntersectionReferenceID& referenceID) override;
    void setCApproachOrLane(const frame::CApproachOrLane & approachOrLane) override;
    void setCVehicleEventFlags(const frame::CVehicleEventFlags& vehicleEventFlags) override;
private:
    element::CTempId tempId_;
    element::CMinuteOfTheYear minuteOfTheYear_;
    Car     bsmCoreData_;
    //CPathHistory pathHistory_;
    frame::CPathPrediction pathPrediction_;
    frame::CIntersectionReferenceID    referenceID_;
    frame::CApproachOrLane approachOrLane_;
    CBrakeSystemStatus brakeSystemStatus_;
    frame::CVehicleEventFlags vehicleEventFlags_;
};
}
