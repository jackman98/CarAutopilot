#pragma once

/*
 * The IntersectionReferenceID data frame conveys the combination of an 
 * optional RoadRegulatorID and of an IntersectionID that is unique within
 * that region.
 *
 * IntersectionReferenceID ::= SEQUENCE {
 *      region RoadRegulatorID OPTIONAL,
 *      id     IntersectionID
 * }
 */

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include "data_elements/RoadRegulatorID.hpp"

namespace v2x{
namespace frame{

using namespace element;

class CIntersectionReferenceID
{
public:
    CIntersectionReferenceID();
    CIntersectionReferenceID(const element::CRoadRegulatorID region, const element::CIntersectionID id);
    virtual ~CIntersectionReferenceID();
 
    CIntersectionID getIntersectionID() const;

    IntersectionID_t getASNIntersectionID() const;
    RoadRegulatorID_t getASNRoadRegulatorID() const;

    void setIntersectionID(IntersectionID_t id);
    void setIntersectionID(CIntersectionID id);
    void setRoadRegulatorID(RoadRegulatorID_t region);
    void setRoadRegulatorID(CRoadRegulatorID region);

    CIntersectionReferenceID& operator=(const CIntersectionReferenceID& rhs);
    int operator==(const CIntersectionReferenceID&) const;
    int operator!=(const CIntersectionReferenceID&) const;
    bool operator<(const CIntersectionReferenceID&) const;

private:
    element::CRoadRegulatorID _region;
    element::CIntersectionID  _id;
};

} /* v2x */
} /* frame */
