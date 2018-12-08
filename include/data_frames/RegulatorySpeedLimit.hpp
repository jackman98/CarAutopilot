#pragma once

namespace v2x {
namespace frame {

    class CRegulatorySpeedLimit {
    public:
        enum SpeedLimitType {
            SpeedLimitType_unknown = 0,
            maxSpeedInSchoolZone = 1,
            maxSpeedInSchoolZoneWhenChildrenArePresent = 2,
            maxSpeedInConstructionZone = 3,
            vehicleMinSpeed = 4,
            vehicleMaxSpeed = 5,
            vehicleNightMaxSpeed = 6,
            truckMinSpeed = 7,
            truckMaxSpeed = 8,
            truckNightMaxSpeed = 9,
            vehiclesWithTrailersMinSpeed = 10,
            vehiclesWithTrailersMaxSpeed = 11,
            vehiclesWithTrailersNightMaxSpeed = 12
        };

        typedef enum SpeedLimitType type;
        typedef unsigned int speed;

        CRegulatorySpeedLimit();
        CRegulatorySpeedLimit(const CRegulatorySpeedLimit&);
        CRegulatorySpeedLimit(type, speed);

        CRegulatorySpeedLimit& operator=(const CRegulatorySpeedLimit&);
        int operator==(const CRegulatorySpeedLimit&) const;
        int operator!=(const CRegulatorySpeedLimit&) const;

        type get_type() const;
        void set_type(type);

        speed get_speed() const;
        void set_speed(speed);

    private:
        type type_field;
        speed speed_field;
    };

} //v2x
} //frame
