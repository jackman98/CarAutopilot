#pragma once

#include "data_elements/CBitString.hpp"
#include "data_elements/LaneID.hpp"

namespace v2x {
namespace frame {

    using namespace element;

    class CConnectingLane {
    public:
        CConnectingLane();
        CConnectingLane(const CConnectingLane&);
        CConnectingLane(const CLaneID&, const CBitString&);
        CConnectingLane(const CLaneID&);

        CConnectingLane& operator=(const CConnectingLane&);
        int operator==(const CConnectingLane&) const;
        int operator!=(const CConnectingLane&) const;

        CLaneID get_lane() const;
        void set_lane(const CLaneID&);

        CBitString get_maneuver() const;
        void set_maneuver(const CBitString&);

    private:
        CLaneID lane_field;
        CBitString maneuver_field;
    };

} //v2x
} //frame
