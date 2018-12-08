#ifndef PATHPREDICTION_HPP
#define PATHPREDICTION_HPP

#pragma once

#include <string>

#include "FullPositionVector.hpp"
#include "GlobalPrimitives.hpp"

namespace v2x {
namespace frame {

class CPathPrediction 
{

public:
    CPathPrediction();
    CPathPrediction(const CPathPrediction &);
    CPathPrediction(element::radiusOfCurve, element::confidence);

    CPathPrediction & operator = (const CPathPrediction &);
    // int operator == (const CPathPrediction &) const;
    // int operator != (const CPathPrediction &) const;

    element::radiusOfCurve & get_radiusOfCurve();
    element::radiusOfCurve get_radiusOfCurve() const;
    void set_radiusOfCurve(element::radiusOfCurve);

    element::confidence & get_confidence();
    element::confidence get_confidence() const;
    void set_confidence(element::confidence);
private:
    element::radiusOfCurve radiusOfCurve_field = 0;
    element::confidence confidence_field = 0;

};
}; //v2x
}; //frame

#endif
