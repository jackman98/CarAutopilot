#pragma once

#include "ConnectingLane.hpp"
#include "IntersectionReferenceID.hpp"
#include "data_elements/LaneConnectionID.hpp"
#include "data_elements/SignalGroupID.hpp"
#include "data_elements/RestrictionClassID.hpp"
#include "data_frames/LaneReferenceID.hpp"

namespace v2x {
namespace frame {


class  CConnection;
typedef std::vector<CConnection> CConnectsToList;


    class CConnection {
    public:
        CConnection();
        CConnection(const CConnection&);
        CConnection(const CConnectingLane&, const CIntersectionReferenceID&, const CSignalGroupID&, const CRestrictionClassID&,
            const CLaneConnectionID&);
        CConnection(const CConnectingLane&);

        CConnection& operator=(const CConnection&);
        int operator==(const CConnection&) const;
        int operator!=(const CConnection&) const;

        CConnectingLane get_connectingLane() const;
        void set_connectingLane(const CConnectingLane&);

        CIntersectionReferenceID get_remoteIntersection() const;
        void set_remoteIntersection(const CIntersectionReferenceID&);

        CSignalGroupID get_signalGroup() const;
        void set_signalGroup(const CSignalGroupID&);

        CRestrictionClassID get_userClass() const;
        void set_userClass(const CRestrictionClassID&);

        CLaneConnectionID get_connectionID() const;
        void set_connectionID(const CLaneConnectionID&);

        CLaneReferenceID get_laneReferanceID() const;
        CAllowedManeuvers get_maneur() const;


    private:
        CConnectingLane connectingLane_field;
        CIntersectionReferenceID remoteIntersection_field;
        CSignalGroupID signalGroup_field;
        CRestrictionClassID userClass_field;
        CLaneConnectionID connectionID_field;
    };

} //v2x
} //frame
