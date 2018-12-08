#ifndef __MOVEMENT_STATE_HPP__
#define __MOVEMENT_STATE_HPP__

/*
 * The MovementState data frame is used to convey various information about the
 * current or future movement state of a designated collection of one or more 
 * lanes of a common type.
 *
 * MovementState ::= SEQUENCE {
 *      movementName     DescriptiveName OPTIONAL,
 *      signalGroup      SignalGroupID,
 *      state-time-speed MovementStateList,
 *      maneuverAssistList ManeuverAssistList OPTIONAL,
 *      regional        SEQUENCE (SIZE(1..4)) OF
 *              RegionalExtension {{REGION.Reg-MovementState}} OPTIONAL,
 *      ...
 * }
 */

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include "AdvisorySpeedList.hpp"
#include "TimeChangeDetails.hpp"
#include "MovementEvent.hpp"

namespace v2x{
namespace frame{

using namespace element;

class CMovementState;
typedef std::vector<std::shared_ptr<CMovementState>> CMovementStateList;

class CMovementState
{
public:
    CMovementState();
    CMovementState(CSignalGroupID &id);
    virtual ~CMovementState();

    CMovementEventList getMovementEventList();
    std::shared_ptr<CMovementEvent> getMovementEvent(unsigned int idx);
    unsigned int addMovementEvent(std::shared_ptr<CMovementEvent> &event);

    void setSignalGroupID(CSignalGroupID &id);
    CSignalGroupID getSignalGroupID();

    CTimeMark getMovementEndTime(unsigned int idx);

private:
    CSignalGroupID _signalGroup;
    CMovementEventList _stateTimeSpeed;

    const unsigned int movementEvenListtLimitSize = 16;

    /* TODO: */
    CDescriptiveName    _movementName;       /* n/a */

//    std::vector<CManeuverAssist>_maneuverAssistList; /* n /a */

/* TODO: investigate */
#ifdef REGIONAL_EXTENSION_ENABLED   
    CRegionalExtension  _regional;
#endif
};

} /* v2x */
} /* frame */
#endif /* __MOVEMENT_STATE_HPP */
