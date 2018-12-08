#pragma once

namespace v2x {
namespace element {

    class CCoordinate {
    public:
        CCoordinate();
        CCoordinate(const CCoordinate&);
        CCoordinate(const int, const int);

        CCoordinate& operator=(const CCoordinate&);
        int operator==(const CCoordinate&) const;
        int operator!=(const CCoordinate&) const;

        int get_lon() const;
        void set_lon(const int lon);

        int get_lat() const;
        void set_lat(const int lat);

    private:
        int lon_field;
        int lat_field;
    };

} //v2x
} //element
