#pragma once

#include "data_elements/CBitString.hpp"

namespace v2x {
namespace frame {

    class CLaneTypeAttributes {
    public:
        enum Id {
            unselected,
            vehicle_chosen = 1,
            crosswalk_chosen = 2,
            bikeLane_chosen = 3,
            sidewalk_chosen = 4,
            median_chosen = 5,
            striping_chosen = 6,
            trackedVehicle_chosen = 7,
            parking_chosen = 8
        };

        CLaneTypeAttributes();
        CLaneTypeAttributes(const CLaneTypeAttributes&);

        CLaneTypeAttributes& operator=(const CLaneTypeAttributes&);
        int operator==(const CLaneTypeAttributes&) const;
        int operator!=(const CLaneTypeAttributes&) const;

        v2x::element::CBitString get_vehicle() const;
        void set_vehicle(const v2x::element::CBitString&);

        v2x::element::CBitString get_crosswalk() const;
        void set_crosswalk(const v2x::element::CBitString&);

        v2x::element::CBitString get_bikeLane() const;
        void set_bikeLane(const v2x::element::CBitString&);

        v2x::element::CBitString get_sidewalk() const;
        void set_sidewalk(const v2x::element::CBitString&);

        v2x::element::CBitString get_median() const;
        void set_median(const v2x::element::CBitString&);

        v2x::element::CBitString get_striping() const;
        void set_striping(const v2x::element::CBitString&);

        v2x::element::CBitString get_trackedVehicle() const;
        void set_trackedVehicle(const v2x::element::CBitString&);

        v2x::element::CBitString get_parking() const;
        void set_parking(const v2x::element::CBitString&);

    private:
        //TODO: add union when apper problem with low memory
        v2x::element::CBitString vehicle_field;
        v2x::element::CBitString crosswalk_field;
        v2x::element::CBitString bikeLane_field;
        v2x::element::CBitString sidewalk_field;
        v2x::element::CBitString median_field;
        v2x::element::CBitString striping_field;
        v2x::element::CBitString trackedVehicle_field;
        v2x::element::CBitString parking_field;
    };

} //v2x
} //frame
