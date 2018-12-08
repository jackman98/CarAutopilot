#pragma once

#include "Latitude.hpp"
#include "Longitude.hpp"
#include "Elevation.hpp"

namespace v2x {
namespace element {

class CPosition3D
{
public:
    CPosition3D();
    CPosition3D(const CPosition3D &);
    CPosition3D(CLatitude, CLongitude, CElevation);
    CPosition3D(CLatitude, CLongitude);

    CPosition3D & operator = (const CPosition3D &);
    int operator == (const CPosition3D &) const;
    int operator != (const CPosition3D &) const;

    CLatitude get_lat() const;
    void set_lat(CLatitude);

    CLongitude get_Position3D_long() const;
    void set_Position3D_long(const CLongitude);

    CElevation get_elevation() const;
    void set_elevation(const CElevation);
private:
    CLatitude lat_field;
    CLongitude long_field;
    CElevation elevation_field;
};



} //v2x
} //element
