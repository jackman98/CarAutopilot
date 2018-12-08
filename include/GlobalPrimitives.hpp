#pragma once

#include "stdint.h"
#include <cstddef>

namespace v2x {
namespace element {

typedef enum PositionConfidence {
    PositionConfidence_unavailable	= 0,
    PositionConfidence_a500m	= 1,
    PositionConfidence_a200m	= 2,
    PositionConfidence_a100m	= 3,
    PositionConfidence_a50m	= 4,
    PositionConfidence_a20m	= 5,
    PositionConfidence_a10m	= 6,
    PositionConfidence_a5m	= 7,
    PositionConfidence_a2m	= 8,
    PositionConfidence_a1m	= 9,
    PositionConfidence_a50cm	= 10,
    PositionConfidence_a20cm	= 11,
    PositionConfidence_a10cm	= 12,
    PositionConfidence_a5cm	= 13,
    PositionConfidence_a2cm	= 14,
    PositionConfidence_a1cm	= 15
} PositionConfidence_t;


typedef long LayerID_type;
typedef enum LayerType {
    none=0,
    mixedContent=1,
    generalMapData=2,
    intersectionData=3,
    curveData=4,
    roadwaySectionData=5,
    parkingAreaData=6,
    sharedLaneData=7
} LayerType_type;

typedef uint16_t yearType; // DYear ::= INTEGER (0..4095) -- units of years
typedef uint8_t monthType; //DMonth ::= INTEGER (0..12) -- units of months
typedef uint8_t dayType; //	DDay ::= INTEGER (0..31)-- units of days
typedef uint8_t hourType; //DHour ::= INTEGER (0..31) -- units of hours
typedef uint8_t minuteType; //DMinute ::= INTEGER (0..60) -- units of minutes
typedef uint16_t secondType; //DSecond ::= INTEGER (0..65535) -- units of milliseconds
typedef int16_t offsetType;//DOffset ::= INTEGER (-840..840) -- units of minutes from UTC time
typedef uint32_t speed;


#if EXCEPTIONS_SUPPORTED
#define OSSTRY try
#define OSSCLEAN(type) catch (...) { this->~type(); throw; }
#define OSSCLEANUP(stmt) catch (...) { stmt throw; }
#else
#define OSSTRY
#define OSSCLEAN(type)
#define OSSCLEANUP
#endif

#ifndef OSS_PUBLIC
#define OSS_PUBLIC
#endif

#define PUBLIC
#define DLL_ENTRY

/* the requested component is missing */
#define OSS_COMPONENT_MISSING		200

void PUBLIC DLL_ENTRY asn1Free(void *ptr);




	typedef uint32_t latOffset;
	typedef uint32_t lonOffset;
	typedef uint32_t elevationOffset;
	typedef uint32_t timeOffset;


	typedef uint32_t heading;

	typedef uint32_t approach;
    typedef uint32_t lane;

    typedef int16_t radiusOfCurve;

    typedef uint8_t confidence;
    
    typedef int32_t elevation;
    /*Elevation ::= INTEGER (-4096..61439)
	-- In units of 10 cm steps above or below the reference ellipsoid
	-- Providing a range of -409.5 to + 6143.9 meters
	-- The value -4096 shall be used when Unknown is to be sent*/

    // typedef uint16_t heading;
	/*ASN.1 Representation:
	Heading ::= INTEGER (0..28800)
	-- LSB of 0.0125 degrees
	-- A range of 0 to 359.9875 degrees*/
    typedef struct TimeConfidence { /* Map with <tag> to integer value association */
		long		 nat_value;	/* associated native integer value */
		size_t		 enum_len;	/* strlen("tag") */
        const char	*enum_name = nullptr;	/* "tag" */
    } TimeConfidence_t;



	typedef enum BrakeAppliedStatus {
		BrakeAppliedStatus_unavailable	= 0,
		BrakeAppliedStatus_leftFront	= 1,
		BrakeAppliedStatus_leftRear	= 2,
		BrakeAppliedStatus_rightFront	= 3,
		BrakeAppliedStatus_rightRear	= 4
	} BrakeAppliedStatus_t;



	typedef enum ElevationConfidence {
		ElevationConfidence_unavailable	= 0,
		ElevationConfidence_elev_500_00	= 1,
		ElevationConfidence_elev_200_00	= 2,
		ElevationConfidence_elev_100_00	= 3,
		ElevationConfidence_elev_050_00	= 4,
		ElevationConfidence_elev_020_00	= 5,
		ElevationConfidence_elev_010_00	= 6,
		ElevationConfidence_elev_005_00	= 7,
		ElevationConfidence_elev_002_00	= 8,
		ElevationConfidence_elev_001_00	= 9,
		ElevationConfidence_elev_000_50	= 10,
		ElevationConfidence_elev_000_20	= 11,
		ElevationConfidence_elev_000_10	= 12,
		ElevationConfidence_elev_000_05	= 13,
		ElevationConfidence_elev_000_02	= 14,
		ElevationConfidence_elev_000_01	= 15
	} ElevationConfidence_t;

	typedef enum HeadingConfidence {
		HeadingConfidence_unavailable	= 0,
		HeadingConfidence_prec10deg	= 1,
		HeadingConfidence_prec05deg	= 2,
		HeadingConfidence_prec01deg	= 3,
		HeadingConfidence_prec0_1deg	= 4,
		HeadingConfidence_prec0_05deg	= 5,
		HeadingConfidence_prec0_01deg	= 6,
		HeadingConfidence_prec0_0125deg	= 7
	} HeadingConfidence_t;	

	typedef enum SpeedConfidence {
		SpeedConfidence_unavailable	= 0,
		SpeedConfidence_prec100ms	= 1,
		SpeedConfidence_prec10ms	= 2,
		SpeedConfidence_prec5ms	= 3,
		SpeedConfidence_prec1ms	= 4,
		SpeedConfidence_prec0_1ms	= 5,
		SpeedConfidence_prec0_05ms	= 6,
		SpeedConfidence_prec0_01ms	= 7
	} SpeedConfidence_t;

	typedef enum ThrottleConfidence {
		ThrottleConfidence_unavailable	= 0,
		ThrottleConfidence_prec10percent	= 1,
		ThrottleConfidence_prec1percent	= 2,
		ThrottleConfidence_prec0_5percent	= 3
	} ThrottleConfidence_t;

	typedef enum VehicleEventFlags {
		VehicleEventFlags_eventHazardLights	= 0,
		VehicleEventFlags_eventStopLineViolation	= 1,
		VehicleEventFlags_eventABSactivated	= 2,
		VehicleEventFlags_eventTractionControlLoss	= 3,
		VehicleEventFlags_eventStabilityControlactivated	= 4,
		VehicleEventFlags_eventHazardousMaterials	= 5,
		VehicleEventFlags_eventReserved1	= 6,
		VehicleEventFlags_eventHardBraking	= 7,
		VehicleEventFlags_eventLightsChanged	= 8,
		VehicleEventFlags_eventWipersChanged	= 9,
		VehicleEventFlags_eventFlatTire	= 10,
		VehicleEventFlags_eventDisabledVehicle	= 11,
		VehicleEventFlags_eventAirBagDeployment	= 12
	} VehicleEventFlags_t;





}
}
