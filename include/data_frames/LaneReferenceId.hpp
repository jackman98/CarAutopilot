#pragma once

#include "data_elements/LaneID.hpp"
#include "data_frames/IntersectionReferenceID.hpp"

namespace v2x {
namespace frame {

    class CLaneReferenceId {
    public:
        CLaneReferenceId();
        CLaneReferenceId(const v2x::element::CLaneID&, const v2x::frame::CIntersectionReferenceID&);

        CLaneReferenceId& operator=(const CLaneReferenceId&);
        int operator==(const CLaneReferenceId&) const;
        int operator!=(const CLaneReferenceId&) const;
        int operator<(const CLaneReferenceId&) const;

        void set_lane(const v2x::element::CLaneID&);
        v2x::element::CLaneID get_lane() const;

        void set_ref(const CIntersectionReferenceID &);
        v2x::frame::CIntersectionReferenceID get_ref() const;

    private:
        v2x::element::CLaneID lane_id;
        v2x::frame::CIntersectionReferenceID ref_id;
    };

} //v2x
} //frame
