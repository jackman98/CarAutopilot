#pragma once

#include <memory>

#include "V2XDataSource.hpp"
#include "Car.hpp"

namespace v2x {
class EmergencyVehicle : public V2XDataSource
{
public:
    EmergencyVehicle();
    virtual ~EmergencyVehicle();

//    void fillDataFromCarObj(std::shared_ptr<v2x::Car> src);

    virtual const CTempId getTempId() const override;
    virtual const CLatitude getLatitude() const override;
    virtual const CLongitude getLongitude() const  override;
    virtual const CVehicleType getVehicleType() const override;
    virtual const CElevation getElevation() const  override { return elevation_; }
    virtual const CPositionAccuracy getPositionAccuracy() const  override { return positionAccuracy_; }
    virtual const CTransmissionState getTransmissionState() const  override { return transmissionState_; }
    virtual const CSpeed getSpeed() const  override { return speed_; }
    virtual const CHeading getHeading() const  override { return heading_; }
    virtual const CSteeringWheelAngle getSteeringWheelAngle() const  override { return steeringWheelAngle_; }
    virtual const CAccelerationSet4Way getAccelerationSet4Way() const  override { return accelerationSet4Way_; }
    virtual const CBrakeSystemStatus getBrakeSystemStatus() const  override { return brakeSystemStatus_; }
    virtual const CVehicleSize getVehicleSize() const override { return vehicleSize_; }
    virtual CDSecond getDsecond() const override { return dsecond_; }

    void setTempId(const CTempId& tempId) override;
    void setLatitude(const CLatitude& latitude) override;
    void setLongitude(const CLongitude& longitude) override;
    void setVehicleType(const CVehicleType& vehicleType) override;
    void setElevation(const CElevation& elevation)  override {elevation_ = elevation;}
    void setPositionAccuracy(const CPositionAccuracy& positionAccuracy) override {positionAccuracy_ = positionAccuracy;}
    void setTransmissionState(const CTransmissionState& transmissionState) override {transmissionState_ = transmissionState;}
    void setSpeed(const CSpeed& speed) override { speed_ = speed;}
    void setHeading(const CHeading& heading) override {heading_ = heading;}
    void setSteeringWheelAngle(const CSteeringWheelAngle& steeringWheelAngle) override {steeringWheelAngle_ = steeringWheelAngle;}
    void setAccelerationSet4Way(const CAccelerationSet4Way& accelerationSet4Way) override {accelerationSet4Way_ = accelerationSet4Way;}
    void setBrakeSystemStatus(const CBrakeSystemStatus& brakeSystemStatus) override {brakeSystemStatus_ = brakeSystemStatus;}
    void setVehicleSize(const CVehicleSize& vehicleSize) override {vehicleSize_ = vehicleSize;}
    void setDSecond(const CDSecond & dsrcond) override { dsecond_ = dsrcond; }

private:
    CTempId tempId_;
    CLatitude latitude_;
    CLongitude longitude_;
    CElevation elevation_;
    CPositionAccuracy positionAccuracy_;
    CTransmissionState transmissionState_;
    CSpeed speed_;
    CHeading heading_;
    CSteeringWheelAngle steeringWheelAngle_;
    CAccelerationSet4Way accelerationSet4Way_;
    CBrakeSystemStatus brakeSystemStatus_;
    CVehicleSize vehicleSize_;
    CVehicleType vtype_;
    CDSecond dsecond_;
};
}

