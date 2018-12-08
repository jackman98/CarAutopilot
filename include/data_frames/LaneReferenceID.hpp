#pragma once

#include "data_elements/LaneID.hpp"
#include "data_frames/IntersectionReferenceID.hpp"

namespace v2x {
namespace frame {

    class CLaneReferenceID {
    public:
        CLaneReferenceID();
        CLaneReferenceID(const v2x::element::CLaneID&, const v2x::frame::CIntersectionReferenceID&);

        CLaneReferenceID& operator=(const CLaneReferenceID&);
        int operator==(const CLaneReferenceID&) const;
        int operator!=(const CLaneReferenceID&) const;
        int operator<(const CLaneReferenceID&) const;

        void set_lane(const v2x::element::CLaneID id);
        v2x::element::CLaneID get_lane() const;

        void set_ref(const CIntersectionReferenceID id);
        v2x::frame::CIntersectionReferenceID get_ref() const;

    private:
        v2x::element::CLaneID lane_id;
        v2x::frame::CIntersectionReferenceID ref_id;
    };

} //v2x
} //frame
