#pragma once

#include "data_elements/PointXY.hpp"
#include "data_elements/Coordinate.hpp"

namespace v2x {
namespace frame {

class CNodeOffsetPointXY {
public:
    enum Id {
        unselected,
        node_XY1_chosen = 1,
        node_XY2_chosen = 2,
        node_XY3_chosen = 3,
        node_XY4_chosen = 4,
        node_XY5_chosen = 5,
        node_XY6_chosen = 6,
        node_LatLon_chosen = 7
    };

    CNodeOffsetPointXY();
    CNodeOffsetPointXY(const element::CCoordinate& latLong);
    CNodeOffsetPointXY(const CNodeOffsetPointXY&);
    ~CNodeOffsetPointXY();

    CNodeOffsetPointXY& operator=(const CNodeOffsetPointXY&);
    int operator==(const CNodeOffsetPointXY&) const;
    int operator!=(const CNodeOffsetPointXY&) const;

    element::CPointXY get_node_XY1() const;
    void set_node_XY1(const element::CPointXY&);

    element::CPointXY get_node_XY2() const;
    void set_node_XY2(const element::CPointXY&);

    element::CPointXY get_node_XY3() const;
    void set_node_XY3(const element::CPointXY&);

    element::CPointXY get_node_XY4() const;
    void set_node_XY4(const element::CPointXY&);

    element::CPointXY get_node_XY5() const;
    void set_node_XY5(const element::CPointXY&);

    element::CPointXY get_node_XY6() const;
    void set_node_XY6(const element::CPointXY&);

    element::CCoordinate get_node_LatLon() const;
    void set_node_LatLon(const element::CCoordinate&);

private:
    //TODO: add union when apper problem with low memory
    element::CPointXY node_XY1_field;
    element::CPointXY node_XY2_field;
    element::CPointXY node_XY3_field;
    element::CPointXY node_XY4_field;
    element::CPointXY node_XY5_field;
    element::CPointXY node_XY6_field;
    element::CCoordinate node_LatLon_field;
};

} //v2x
} //frame
