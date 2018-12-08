#pragma once
#include "MAPDataSource.hpp"
#include "msg/MAPMessage.hpp"

namespace v2x {

class MapUpdate : public MAPDataSource
{
public:
    MapUpdate();
    virtual ~MapUpdate() override;

    virtual element::CMinuteOfTheYear gettimeStamp() override;
    virtual long getmsgIssueRevision() override;

    virtual element::LayerType_type getLayerType() const override;
    virtual element::LayerID_type getLayerID() const override;
//    virtual  frame::CParkingArea getParkingAreas() const override;
    virtual frame::CIntersectionList getIntersectionGeometryLists() const override;
    virtual frame::CRoadSegmentList getRoadSegmentLists() const override;
//    virtual  v2x::element::CDataParameters getDataParameters() const override;
//    virtual  frame::CRestrictionClassList getRestrictionClassList() const override;

    void settimeStamp(const element::CMinuteOfTheYear& timestamp) override;
    void setmsgIssueRevision(const long& msgissuerevision) override;
    void setLayerType(const element::LayerType_type& layertype) override;
    void setLayerID(const element::LayerID_type& layerid) override;
//    void setParkingArea(const frame::CParkingArea& parkingarea);
    void setIntersectionGeometryList(const frame::CIntersectionList& intersectiongeometrylist) override;
    void setRoadSegmentList(const frame::CRoadSegmentList& roadsegmentlist) override;
//    void setDataParameters(v2x::element::CDataParameters& dataparameters);
//    void setRestrictionClassList(frame::CRestrictionClassList& restrictionclasslist);

private:
    long msgissuerevision_;
    element::CMinuteOfTheYear timestamp_;
    element::LayerType_type layertype_;
    element::LayerID_type layerid_;
//    v2x::frame::CParkingArea parkingarea_;
    v2x::frame::CIntersectionList intersectiongeometrylist_;
    v2x::frame::CRoadSegmentList roadsegmentlist_;
//    v2x::element::CDataParameters dataparameters_;
//    v2x::frame::CRestrictionClassList restrictionclasslist_;
};
}

