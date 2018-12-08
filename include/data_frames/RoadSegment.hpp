#pragma once

#include <string>

#include "data_elements/RoadSegmentReferenceID.hpp"
#include "data_elements/Position3D.hpp"
#include "GenericLane.hpp"
#include "RegulatorySpeedLimit.hpp"

namespace v2x {
namespace frame {

    using namespace element;

    //    typedef __shared2 speedLimits;
    //    typedef __shared9 roadLaneSet;

    class  CRoadSegment;
    typedef std::vector<std::shared_ptr<CRoadSegment>> CRoadSegmentList;

    class CRoadSegment {
    public:
        CRoadSegment();
        CRoadSegment(const CRoadSegment&);
        CRoadSegment(const std::string&, const CRoadSegmentReferenceID&, unsigned int, const CPosition3D&, unsigned int,
            const CRegulatorySpeedLimit&, const CLaneList&);
        CRoadSegment(const CRoadSegmentReferenceID&, unsigned int, const CPosition3D&, const CLaneList&);

        CRoadSegment& operator=(const CRoadSegment&);
        int operator==(const CRoadSegment&) const;
        int operator!=(const CRoadSegment&) const;

        std::string get_name() const;
        void set_name(const std::string&);

        CRoadSegmentReferenceID get_id();
        void set_id(const CRoadSegmentReferenceID&);

        unsigned int get_revision() const;
        void set_revision(unsigned int);

        CPosition3D get_refPoint() const;
        void set_refPoint(const CPosition3D&);

        unsigned int get_laneWidth() const;
        void set_laneWidth(const unsigned int);

        const CRegulatorySpeedLimit get_speedLimits() const;
        void set_speedLimits(const CRegulatorySpeedLimit&);

        CLaneList get_roadLaneSet() const;
        void set_roadLaneSet(const CLaneList&);

    private:
        std::string name_field;
        CRoadSegmentReferenceID id_field;
        unsigned int revision_field;
        CPosition3D refPoint_field;
        unsigned int laneWidth_field;
        CRegulatorySpeedLimit speedLimits_field;
        CLaneList roadLaneSet_field;
    };

} //v2x
} //frame
