#ifndef __PEDESTRIAN_BICYCLE_DETECT_HPP__
#define __PEDESTRIAN_BICYCLE_DETECT_HPP__

#include "PedestrianBicycleDetect.h"

/*
 * Data element is used to provide an indication of whether Pedestrians and/or
 * Bicyclists have been detected in the crossing lane.
 *
 * PedestrianBicycleDetect ::= BOOLEAN
 * -- true if ANY Pedestrians or Bicyclists are
 * -- detected crossing the target lane or lanes
 */

namespace v2x {
namespace element {

class CPedestrianBicycleDetect
{
public:
    CPedestrianBicycleDetect();
    CPedestrianBicycleDetect(const PedestrianBicycleDetect_t& value);
    virtual ~CPedestrianBicycleDetect();

    CPedestrianBicycleDetect get();
    void set(const PedestrianBicycleDetect_t& value);

    CPedestrianBicycleDetect& operator=(const PedestrianBicycleDetect_t& rhs);

private:
    PedestrianBicycleDetect_t _pedestrian_bicycle_detect;
};

} /* v2x */
} /* element */
#endif /* __PEDESTRIAN_BICYCLE_DETECT_HPP__ */
