#ifndef POSITIONCONFIDENCESET_HPP
#define POSITIONCONFIDENCESET_HPP

#pragma once

#include <string.h>

#include "GlobalPrimitives.hpp"

namespace v2x {
namespace frame {

class OSS_PUBLIC CPositionConfidenceSet   /* SEQUENCE */
{
public:
    CPositionConfidenceSet();
    CPositionConfidenceSet(const CPositionConfidenceSet &);
    CPositionConfidenceSet(element::PositionConfidence_t, element::ElevationConfidence_t);
    ~CPositionConfidenceSet();

    CPositionConfidenceSet & operator = (const CPositionConfidenceSet &);
    int operator == (const CPositionConfidenceSet &) const;
    int operator != (const CPositionConfidenceSet &) const;

    element::PositionConfidence_t & get_pos();
    element::PositionConfidence_t get_pos() const;
    void set_pos(element::PositionConfidence_t);

    element::ElevationConfidence_t & get_elevation();
    element::ElevationConfidence_t get_elevation() const;
    void set_elevation(element::ElevationConfidence_t);
private:
    element::PositionConfidence_t pos_field;
    element::ElevationConfidence_t elevation_field;
};

};
};

#endif
