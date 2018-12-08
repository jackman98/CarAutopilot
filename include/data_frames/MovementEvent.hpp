#ifndef __MOVEMENT_EVENT_HPP__
#define __MOVEMENT_EVENT_HPP__

/*
 * The MovementEvent data frame contains details about a single movement. It is
 * used by the movement state to convey one of number of movements (typically 
 * occurring over a sequence of times) for a SignalGroupID. 
 *
 * MovementEvent ::= SEQUENCE {
 *      eventState MovementPhaseState,
 *      timing     TimeChangeDetails OPTIONAL,
 *      speeds     AdvisorySpeedList OPTIONAL,
 *      regional   SEQUENCE (SIZE(1..4)) OF
 *               RegionalExtension {{REGION.Reg-MovementEvent}} OPTIONAL,
 *      ...
 * }
 */

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include "AdvisorySpeedList.hpp"
#include "TimeChangeDetails.hpp"

namespace v2x{
namespace frame{

using namespace element;

class CMovementEvent;
typedef std::vector<std::shared_ptr<CMovementEvent>> CMovementEventList;

class CMovementEvent
{
public:
    CMovementEvent();
    virtual ~CMovementEvent();

    eMovementPhaseState_t getMovementPhaseState();
    void setMovementPhaseState(eMovementPhaseState_t state);

    CTimeChangeDetails getCTimeChangeDetails();
 
    CTimeMark getMinEndTime(void);
    void setMinEndTime(CTimeMark &time);

private:
    eMovementPhaseState_t _eventState;
    CTimeChangeDetails    _timing;

    /* TODO: n/a */
    CAdvisorySpeedList    _speeds;

/* TODO: investigate */
#ifdef REGIONAL_EXTENSION_ENABLED   
    CRegionalExtension  _regional;
#endif
};

} /* v2x */
} /* frame */
#endif /* __MOVEMENT_EVENT_HPP */
