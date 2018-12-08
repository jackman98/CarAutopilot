#ifndef __ROAD_REGULATOR_ID_HPP__
#define __ROAD_REGULATOR_ID_HPP__

#include "RoadRegulatorID.h"

/*
 * The RoadRegulatorID is a 16-bit globally unique identifier assigned to an
 * entity responsible for assigning Intersection IDs in the region over which
 * it has such authority.
 * 
 * RoadRegulatorID ::= INTEGER (0..65535)
 */

namespace v2x {
namespace element {

class CRoadRegulatorID
{
public:
    CRoadRegulatorID();
    CRoadRegulatorID(const RoadRegulatorID_t& value);
    virtual ~CRoadRegulatorID();

    RoadRegulatorID_t get() const;
    void set(const RoadRegulatorID_t& value);

    CRoadRegulatorID& operator=(const CRoadRegulatorID& rhs);
    CRoadRegulatorID& operator=(const RoadRegulatorID_t& rhs);
    int operator==(const CRoadRegulatorID&) const;
    int operator!=(const CRoadRegulatorID&) const;
    int operator<(const CRoadRegulatorID&) const;

private:
    RoadRegulatorID_t _road_regulator_id;
};

} /* v2x */
} /* element */
#endif /* __ROAD_REGULATOR_ID_HPP__ */
