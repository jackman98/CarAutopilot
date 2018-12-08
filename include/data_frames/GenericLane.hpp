#pragma once

#include <vector>
#include <memory>
#include "LaneAttributes.hpp"
#include "NodeXY.hpp"
#include "Connection.hpp"
#include "LaneReferenceID.hpp"
#include "data_elements/CBitString.hpp"
#include "IntersectionReferenceID.hpp"

namespace v2x {
namespace frame {

    class CGenericLane;
    typedef std::vector<std::shared_ptr<CGenericLane> > CLaneList;
    
    //TODO: add overlays
    //    typedef __shared8 overlays;
    typedef int COverlays;

    class CGenericLane {
    public:
        CGenericLane();
        CGenericLane(const CGenericLane&);
        CGenericLane(const CLaneID&, const CLaneReferenceID&, const std::string& name,
            uint32_t ingressApproach, const uint32_t egressApproach,
            const CLaneAttributes&, const v2x::element::CBitString&, const CNodeXYList&,
            const CConnectsToList&); //const COverlays& overlays
        CGenericLane(const CLaneID&, const CLaneAttributes&, const CNodeXYList&);
        CGenericLane(const CLaneID& laneID);
        CGenericLane(const CLaneReferenceID& refID);
        CGenericLane(const CLaneID& laneID, const CIntersectionReferenceID& intersectionID);


        CGenericLane& operator=(const CGenericLane&);
        int operator==(const CGenericLane&) const;
        int operator!=(const CGenericLane&) const;

        CLaneID get_laneID() const;
        void set_laneID(CLaneID);

        CLaneReferenceID get_laneRef() const;
        void set_laneRef(const CLaneReferenceID id);

        CIntersectionReferenceID get_intersectionID() const;
        void set_intersectionID(const CIntersectionReferenceID id);

        std::string get_name() const;
        void set_name(const std::string&);

        uint32_t get_ingressApproach() const;
        void set_ingressApproach(uint32_t);

        uint32_t get_egressApproach() const;
        void set_egressApproach(uint32_t);

        CLaneAttributes get_laneAttributes() const;
        void set_laneAttributes(const CLaneAttributes&);

        v2x::element::CBitString get_maneuvers() const;
        void set_maneuvers(const v2x::element::CBitString&);

        CNodeXYList get_nodeList() const;
        void set_nodeList(const CNodeXYList&);
        void addNode(const CNodeXY& node);
        void addNode(const CCoordinate& node);
        void clearNodeList();

        CConnectsToList get_connectsToList() const;
        void set_connectsToList(const CConnectsToList&);
        void clearConnectsToList();
        void addConnection(const std::shared_ptr<CGenericLane> lane, const CBitString& maneurs);
        void addConnection(const CConnection conn);

        int get_numberOnTheRoad() const;
        void set_numberOnTheRoad(int number);

        //TODO: add overlays
        // COverlays get_overlays() const;
        // void set_overlays(const COverlays&);

    private:
        CLaneID laneID_field;
        CLaneReferenceID laneRef_field;
        std::string name_field;
        uint32_t ingressApproach_field;
        uint32_t egressApproach_field;
        CLaneAttributes laneAttributes_field;
        CBitString maneuvers_field;
        CNodeXYList nodeList_field;
        CConnectsToList connectsTo_field;
        int numberOnTheRoad_field;
        //TODO: add overlays
        // COverlays overlays_field;
    };

} //v2x
} //frame
