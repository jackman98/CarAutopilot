#pragma once

#include "data_elements/CBitString.hpp"
#include "LaneTypeAttributes.hpp"

namespace v2x {
namespace frame {

    class CLaneAttributes {
    public:
        enum LaneDirection {
            ingressPath = 0,
            egressPath = 1
        };

        CLaneAttributes();
        CLaneAttributes(const CLaneAttributes&);
        CLaneAttributes(const v2x::element::CBitString&, const v2x::element::CBitString&, const CLaneTypeAttributes&);

        CLaneAttributes& operator=(const CLaneAttributes&);
        int operator==(const CLaneAttributes&) const;
        int operator!=(const CLaneAttributes&) const;

        v2x::element::CBitString get_directionalUse() const;
        void set_directionalUse(const v2x::element::CBitString&);

        v2x::element::CBitString get_sharedWith() const;
        void set_sharedWith(const v2x::element::CBitString&);

        CLaneTypeAttributes get_laneType() const;
        void set_laneType(const CLaneTypeAttributes&);

    private:
        v2x::element::CBitString directionalUse_field;
        v2x::element::CBitString sharedWith_field;
        CLaneTypeAttributes laneType_field;
    };

} //v2x
} //frame
