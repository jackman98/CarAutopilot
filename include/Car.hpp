#ifndef CAR_H__
#define CAR_H__

#include "V2XDataSource.hpp"

namespace v2x {

class Car : public V2XDataSource
{
public:
    Car();
    virtual ~Car();

    virtual const CTempId getTempId() const override;
    virtual const CLatitude getLatitude() const override;
    virtual const CLongitude getLongitude() const  override;
    virtual const CElevation getElevation() const override;
    virtual const CPositionAccuracy getPositionAccuracy() const override;
    virtual const CTransmissionState getTransmissionState() const override;
    virtual const CSpeed getSpeed() const override;
    virtual const CHeading getHeading() const override;
    virtual const CSteeringWheelAngle getSteeringWheelAngle() const override;
    virtual const CAccelerationSet4Way getAccelerationSet4Way() const override;
    virtual const CBrakeSystemStatus getBrakeSystemStatus() const override;
    virtual const CVehicleSize getVehicleSize() const override;
    virtual const CVehicleType getVehicleType() const override;
    virtual CDSecond getDsecond() const override;

    void setTempId(const CTempId& tempId) override;
    void setLatitude(const CLatitude& latitude) override;
    void setLongitude(const CLongitude& longitude) override;
    void setElevation(const CElevation& elevation) override;
    void setPositionAccuracy(const CPositionAccuracy& positionAccuracy) override;
    void setTransmissionState(const CTransmissionState& transmissionState) override;
    void setSpeed(const CSpeed& speed) override;
    void setHeading(const CHeading& heading) override;
    void setSteeringWheelAngle(const CSteeringWheelAngle& steeringWheelAngle) override;
    void setAccelerationSet4Way(const CAccelerationSet4Way& accelerationSet4Way) override;
    void setBrakeSystemStatus(const CBrakeSystemStatus& brakeSystemStatus) override;
    void setVehicleSize(const CVehicleSize& vehicleSize) override;
    void setVehicleType(const CVehicleType& vehicleType) override;
    void setDSecond(const CDSecond & dsecond) override;

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

} //v2x

#endif
