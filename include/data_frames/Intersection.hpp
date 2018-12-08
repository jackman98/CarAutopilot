#pragma once

#include <string>

#include "IntersectionReferenceID.hpp"
#include "data_elements/Position3D.hpp"
#include "GenericLane.hpp"
#include "RegulatorySpeedLimit.hpp"
#include "IntersectionState.hpp"

namespace v2x {
namespace frame {

    class  CIntersection;
    typedef std::vector<std::shared_ptr<CIntersection>> CIntersectionList;

    class CIntersection {
    public:
        typedef char preemptPriorityData;

        CIntersection();
        CIntersection(const CIntersectionReferenceID& id);
        CIntersection(const CIntersection&);
        CIntersection(const std::string&, const CIntersectionReferenceID&, unsigned int, const element::CPosition3D&, unsigned int,
            const CRegulatorySpeedLimit&, const CLaneList&, const preemptPriorityData&);
        CIntersection(const CIntersectionReferenceID&, unsigned int, const element::CPosition3D&, const CLaneList&);

        CIntersection& operator=(const CIntersection&);
        int operator==(const CIntersection&) const;
        int operator!=(const CIntersection&) const;

        std::string get_name() const;
        void set_name(const std::string&);

        CIntersectionReferenceID get_id() const;
        void set_id(const CIntersectionReferenceID&);

        unsigned int get_revision() const;
        void set_revision(unsigned int);

        CPosition3D get_refPoint() const;
        void set_refPoint(const CPosition3D&);

        unsigned int get_laneWidth() const;
        void set_laneWidth(const unsigned int);

        const CRegulatorySpeedLimit get_speedLimits() const;
        void set_speedLimits(const CRegulatorySpeedLimit&);

        CLaneList get_laneSet() const;
        void set_laneSet(const CLaneList&);
        std::shared_ptr<CGenericLane> getLane(CLaneID);
        void addLane(std::shared_ptr<CGenericLane> lane);
        void clearLaneSet();

        CIntersectionStateList getIntersectionStateList() const;
        std::shared_ptr<CIntersectionState> getIntersectionState(unsigned int state_idx);
        unsigned int addIntersectionState(std::shared_ptr<CIntersectionState> state);
        void clearIntersectionStateList();

        CMovementEventList getMovementEventsForLane(CLaneID id);

        const char* get_preemptPriorityData() const;
        void set_preemptPriorityData(const char&);

    private:
        std::string name_field;
        CIntersectionReferenceID id_field;
        unsigned int revision_field = 0;
        CPosition3D refPoint_field;
        unsigned int laneWidth_field = 0;
        CRegulatorySpeedLimit speedLimits_field;
        CLaneList laneSet_field;
        CIntersectionStateList states_field;
        preemptPriorityData preemptPriorityData_field;
    };

} //v2x
} //frame
