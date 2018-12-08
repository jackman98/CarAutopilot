#ifndef V2X_DATA_SOURCE_HPP__
#define V2X_DATA_SOURCE_HPP__

#include "data_elements/Latitude.hpp"
#include "data_elements/Longitude.hpp"
#include "data_elements/Elevation.hpp"
#include "data_elements/TransmissionState.hpp"
#include "data_elements/Speed.hpp"
#include "data_elements/Heading.hpp"
#include "data_elements/SteeringWheelAngle.hpp"
#include "data_elements/TempId.hpp"
#include "data_elements/VehicleType.hpp"
#include "data_frames/PositionAccuracy.hpp"
#include "data_frames/AccelerationSet4Way.hpp"
#include "data_frames/BrakeSystemStatus.hpp"
#include "data_frames/VehicleSize.hpp"
#include "data_elements/DSecond.hpp"

using namespace v2x::element;

class V2XDataSource
{
public:
    virtual const CTempId getTempId() const = 0;
    virtual const CLatitude getLatitude() const = 0;
    virtual const CLongitude getLongitude() const = 0;
    virtual const CElevation getElevation() const = 0;
    virtual const CPositionAccuracy getPositionAccuracy() const = 0;
    virtual const CTransmissionState getTransmissionState() const = 0;
    virtual const CSpeed getSpeed() const = 0;
    virtual const CHeading getHeading() const = 0;
    virtual const CSteeringWheelAngle getSteeringWheelAngle() const = 0;
    virtual const CAccelerationSet4Way getAccelerationSet4Way() const = 0;
    virtual const CBrakeSystemStatus getBrakeSystemStatus() const = 0;
    virtual const CVehicleSize getVehicleSize() const = 0;
    virtual const CVehicleType getVehicleType() const = 0;
    virtual CDSecond getDsecond() const = 0;

    virtual void setTempId(const CTempId& tempId) = 0;
    virtual void setLatitude(const CLatitude& latitude) = 0;
    virtual void setLongitude(const CLongitude& longitude) = 0;
    virtual void setElevation(const CElevation& elevation) = 0;
    virtual void setPositionAccuracy(const CPositionAccuracy& positionAccuracy) = 0;
    virtual void setTransmissionState(const CTransmissionState& transmissionState) = 0;
    virtual void setSpeed(const CSpeed& speed) = 0;
    virtual void setHeading(const CHeading& heading) = 0;
    virtual void setSteeringWheelAngle(const CSteeringWheelAngle& steeringWheelAngle) = 0;
    virtual void setAccelerationSet4Way(const CAccelerationSet4Way& accelerationSet4Way) = 0;
    virtual void setBrakeSystemStatus(const CBrakeSystemStatus& brakeSystemStatus) = 0;
    virtual void setVehicleSize(const CVehicleSize& vehicleSize) = 0;
    virtual void setVehicleType(const CVehicleType& vehicleType) = 0;
    virtual void setDSecond(const CDSecond & dsrcond) = 0;
};

#endif
