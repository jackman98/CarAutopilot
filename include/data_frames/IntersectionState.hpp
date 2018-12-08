#ifndef __INTERSECTION_STATE_HPP__
#define __INTERSECTION_STATE_HPP__

/*
 * The IntersectionState data frame is used to convey various information about the
 * current or future movement state of a designated collection of one or more 
 * lanes of a common type.
 *
 * IntersectionState ::= SEQUENCE {
 *      movementName     DescriptiveName OPTIONAL,
 *      signalGroup      SignalGroupID,
 *      state-time-speed IntersectionStateList,
 *      maneuverAssistList ManeuverAssistList OPTIONAL,
 *      regional        SEQUENCE (SIZE(1..4)) OF
 *              RegionalExtension {{REGION.Reg-IntersectionState}} OPTIONAL,
 *      ...
 * }
 */

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include "EnabledLaneList.hpp"
#include "MovementState.hpp"
#include "IntersectionReferenceID.hpp"

namespace v2x{
namespace frame{

using namespace element;

class CIntersectionState;
typedef std::vector<std::shared_ptr<CIntersectionState>> CIntersectionStateList;

class CIntersectionState
{
public:
    CIntersectionState();
    CIntersectionState(CIntersectionReferenceID &id,
                       CMinuteOfTheYear &moy,
                       CMsgCount &revision,
                       CIntersectionStatusObject &status);

    ~CIntersectionState();
  

    CMovementStateList getMovementStateList();
    std::shared_ptr<CMovementState>  getMovementState(unsigned int idx);
    unsigned int addMovementState(std::shared_ptr<CMovementState> state);

    CMovementEventList getMovementEventsFoLane(CLaneID id);
 
    CIntersectionReferenceID getIntersectionReferenceID(void) const;
    CMinuteOfTheYear getMinuteOfTheYear(void);
    CMsgCount getMsgCount(void);
    CIntersectionStatusObject getIntersectionStatusObject(void);
    std::vector<CLaneID> getEnabledLaneList();
    CLaneID getLaneID(unsigned int idx);
   
    void setIntersectionReferenceID(const CIntersectionReferenceID &id);
    void setMinuteOfTheYear(CMinuteOfTheYear &moy);
    void setMsgCount(CMsgCount &msgCnt);
    void setIntersectionStatusObject(CIntersectionStatusObject &status);

    unsigned int addLaneID(const CLaneID laneId);
  
    CTimeMark getMovementEndTime(unsigned int idx);

private:
    CIntersectionReferenceID  _id;
    CMinuteOfTheYear          _moy;
    CMsgCount                 _revision;
    CIntersectionStatusObject _status;

    std::vector<CLaneID>      _enabledLaneList;
    CMovementStateList        _states;

   
    const unsigned int movementStateSizeLimit = 255;
    const unsigned int enabledLaneListSizeLimit =  16;
    /* TODO: */
    /* n /a */
    CDescriptiveName          *_name;
    CDSecond                  _timeStamp;
    
/* TODO: investigate */
#ifdef REGIONAL_EXTENSION_ENABLED   
    CRegionalExtension  _regional;
#endif
};

} /* v2x */
} /* frame */
#endif /* __INTERSECTION_STATE_HPP__ */
