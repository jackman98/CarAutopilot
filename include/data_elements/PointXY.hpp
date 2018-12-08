#pragma once

namespace v2x {
namespace element {

    class CPointXY {
    public:
        CPointXY();
        CPointXY(const CPointXY&);
        CPointXY(const unsigned int, const unsigned int);

        CPointXY& operator=(const CPointXY&);
        int operator==(const CPointXY&) const;
        int operator!=(const CPointXY&) const;

        unsigned int get_x() const;
        void set_x(const unsigned int);

        unsigned int get_y() const;
        void set_y(const unsigned int);

    private:
        unsigned int x_field;
        unsigned int y_field;
    };

} //v2x
} //element
