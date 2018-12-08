#ifndef __CONNECTION_MANEUVER_ASSIST_HPP__
#define __CONNECTION_MANEUVER_ASSIST_HPP___

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

/*
 * The ConnectionManeuverAssist data frame contains information about the the
 * dynamic flow of traffic for the lane(s) and maneuvers in question (as
 *  determined by the LaneConnectionID)
 *
 * ConnectionManeuverAssist ::= SEQUENCE {
 *     connectionID       LaneConnectionID,
 *     queueLength        ZoneLength OPTIONAL,
 *     availableStorageLength ZoneLength OPTIONAL,
 *     waitOnStop         WaitOnStopline OPTIONAL,
 *     pedBicycleDetect   PedestrianBicycleDetect OPTIONAL,
 *     regional SEQUENCE (SIZE(1..4)) OF
 *           RegionalExtension {{REGION.Reg-ConnectionManeuverAssist}} OPTIONAL,
 *     ...
 * }
 */

namespace v2x{
namespace frame{

using namespace element;

class CConnectionManeuverAssist
{
public:
    CConnectionManeuverAssist();
    virtual ~CConnectionManeuverAssist();

private:
    CLaneConnectionID  _connectionId;
    CZoneLength        _queueLength;
    CZoneLength        _availableStorageLength;
    CWaitOnStopLine    _waitOnStopLine;
    
/* TODO: investigate */
#ifdef REGIONAL_EXTENSION_ENABLED   
    CRegionalExtension  _regional;
#endif
};

} /* v2x */
} /* frame */
#endif /* __CONNECTION_MANEUVER_ASSIST_HPP__ */
