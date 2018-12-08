#pragma once

#include "NodeOffsetPointXY.hpp"
#include "NodeAttributeSetXY.hpp"

namespace v2x {
namespace frame {

    class CNodeXY;
    typedef std::vector<CNodeXY> CNodeXYList;

    class CNodeXY {
    public:
        CNodeXY();
        CNodeXY(const CNodeXY&);
        CNodeXY(const CNodeOffsetPointXY&, const CNodeAttributeSetXY&);
        CNodeXY(const CNodeOffsetPointXY&);
        CNodeXY(const element::CCoordinate& coord);

        CNodeXY& operator=(const CNodeXY&);
        int operator==(const CNodeXY&) const;
        int operator!=(const CNodeXY&) const;

        element::CCoordinate get_LatLon() const;
        void set_LatLon(const element::CCoordinate& coord);

        CNodeOffsetPointXY get_delta() const;
        void set_delta(const CNodeOffsetPointXY&);

        CNodeAttributeSetXY get_attributes() const;
        void set_attributes(const CNodeAttributeSetXY&);

    private:
        CNodeOffsetPointXY delta_field;
        CNodeAttributeSetXY attributes_field;
    };

} //v2x
} //frame
