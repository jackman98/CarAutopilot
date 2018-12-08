#pragma once

#include <memory>
#include <map>

#include "data_frames/RoadSegment.hpp"
#include "data_frames/Intersection.hpp"
#include "data_frames/IntersectionReferenceID.hpp"
#include "data_frames/GenericLane.hpp"
//#include "LaneReferenceID.hpp"

namespace v2x {

class CMapStorage
{
private:
    CMapStorage();
    ~CMapStorage();

    // delete copy and move constructors and assign operators
    CMapStorage(CMapStorage const&) = delete;             // Copy construct
    CMapStorage(CMapStorage&&) = delete;                  // Move construct
    CMapStorage& operator=(CMapStorage const&) = delete;  // Copy assign
    CMapStorage& operator=(CMapStorage &&) = delete;      // Move assign

public:
    static CMapStorage& Instance();

    void addIntersection(std::shared_ptr<frame::CIntersection>);
    void addRoadSegment(std::shared_ptr<frame::CRoadSegment>);

private:
    // TODO: implement with std::unordered_map
    std::map<frame::CIntersectionReferenceID, std::shared_ptr<frame::CIntersection>> _intersections;
    std::map<element::CRoadSegmentReferenceID, std::shared_ptr<frame::CRoadSegment>> _roadSegments;

//    std::unordered_map</*CLaneReferenceID*/int, frame::CGenericLane> _unfinishedLanes;
//    std::unordered_map<frame::CIntersectionReferenceID, std::shared_ptr<frame::CIntersectionGeometry>> _unfinishedIntersections;
//    std::unordered_map<element::CRoadSegmentReferenceID, std::shared_ptr<frame::CRoadSegment>> _unfinishedRoadSegments;
};

} // namespace v2x
