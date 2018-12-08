#ifndef VEHICLE_TYPE_HPP__
#define VEHICLE_TYPE_HPP__

#include "VehicleType.h"
#include "V2XEnums.hpp"

//The DE_VehicleType data element is a type list (i.e., a classification list)
//of the vehicle in terms of overall size. The data element entries follow the
//definitions defined in the US DOT Highway Performance Monitoring System (HPMS).
//Many infrastructure roadway operators collect and classify data according to
//this list for regulatory reporting needs. Within the ITS industry and within
//the DSRC message set standards work, there are many similar lists of types for
//overlapping needs and uses.

namespace v2x {
    namespace element {
        class CVehicleType
        {
        public:
            explicit CVehicleType();
            CVehicleType(const VehicleType_t& value);
            CVehicleType(const eVehicleType_t& value);
            virtual ~CVehicleType();

            explicit operator VehicleType_t() const;
            explicit operator eVehicleType_t() const;

            void set(const VehicleType_t& value);
            void set(const eVehicleType_t& value);

        private:
            VehicleType_t value_;
            eVehicleType_t C2PlusPlus(const VehicleType_t value) const;
            VehicleType_t PlusPlus2C(const eVehicleType_t value) const;
        };
    }
}

#endif /* VEHICLE_TYPE_HPP__ */
