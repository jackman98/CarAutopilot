#pragma once

#include "msg/MessageCounter.hpp"
#include "GlobalPrimitives.hpp"
#include "data_frames/Intersection.hpp"
#include "data_frames/RoadSegment.hpp"
#include "data_elements/MinuteOfTheYear.hpp"

namespace v2x {


class MAPDataSource
{
public:
    virtual ~MAPDataSource() {}

    virtual element::CMinuteOfTheYear gettimeStamp() = 0;
    virtual long getmsgIssueRevision() = 0;

    virtual element::LayerType_type getLayerType() const = 0;
    virtual element::LayerID_type getLayerID() const = 0;
//    virtual frame::CParkingArea getParkingAreas();
    virtual frame::CIntersectionList getIntersectionGeometryLists() const = 0;
    virtual frame::CRoadSegmentList getRoadSegmentLists() const = 0;
//    virtual element::CDataParameters getDataParameters();
//    virtual frame::CRestrictionClassList getRestrictionClassList();

    virtual void settimeStamp(const element::CMinuteOfTheYear& timestamp) = 0;
    virtual void setmsgIssueRevision(const long& msgissuerevision) = 0;
    virtual void setLayerType(const element::LayerType_type& layertype) = 0;
    virtual void setLayerID(const element::LayerID_type& layerid) = 0;
//    virtual void setParkingArea(const frame::CParkingArea& parkingarea) = 0;
    virtual void setIntersectionGeometryList(const frame::CIntersectionList& intersectiongeometrylist) = 0;
    virtual void setRoadSegmentList(const frame::CRoadSegmentList& roadsegmentlist) = 0;
//    virtual void setDataParameters(element::CDataParameters& dataparameters) = 0; //TODO: after implementing don't forget to add it in MAPMessage class
//    virtual void setRestrictionClassList(frame::CRestrictionClassList& restrictionclasslist) = 0; //TODO: after implementing don't forget to add it in MAPMessage class
};

}
