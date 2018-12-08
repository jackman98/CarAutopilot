#pragma once

#include "LaneDataAttribute.hpp"

namespace v2x {
namespace frame {

    class CNodeAttributeSetXY {

    public:
        enum NodeAttributeXY {
            NodeAttributeXY_reserved = 0,
            NodeAttributeXY_stopLine = 1,
            NodeAttributeXY_roundedCapStyleA = 2,
            NodeAttributeXY_roundedCapStyleB = 3,
            NodeAttributeXY_mergePoint = 4,
            NodeAttributeXY_divergePoint = 5,
            NodeAttributeXY_downstreamStopLine = 6,
            NodeAttributeXY_downstreamStartNode = 7,
            NodeAttributeXY_closedToTraffic = 8,
            NodeAttributeXY_safeIsland = 9,
            NodeAttributeXY_curbPresentAtStepOff = 10
        };

        enum SegmentAttributeXY {
            SegmentAttributeXY_reserved = 0,
            SegmentAttributeXY_doNotBlock = 1,
            SegmentAttributeXY_whiteLine = 2,
            SegmentAttributeXY_mergingLaneLeft = 3,
            SegmentAttributeXY_mergingLaneRight = 4,
            SegmentAttributeXY_curbOnLeft = 5,
            SegmentAttributeXY_curbOnRight = 6,
            SegmentAttributeXY_loadingzoneOnLeft = 7,
            SegmentAttributeXY_loadingzoneOnRight = 8,
            SegmentAttributeXY_turnOutPointOnLeft = 9,
            turnOutPointOnRight = 10,
            SegmentAttributeXY_adjacentParkingOnLeft = 11,
            adjacentParkingOnRight = 12,
            adjacentBikeLaneOnLeft = 13,
            adjacentBikeLaneOnRight = 14,
            SegmentAttributeXY_sharedBikeLane = 15,
            SegmentAttributeXY_transitStopOnLeft = 16,
            SegmentAttributeXY_transitStopOnRight = 17,
            SegmentAttributeXY_transitStopInLane = 18,
            SegmentAttributeXY_sharedWithTrackedVehicle = 19,
            SegmentAttributeXY_safeIsland = 20,
            SegmentAttributeXY_lowCurbsPresent = 21,
            SegmentAttributeXY_rumbleStripPresent = 22,
            SegmentAttributeXY_audibleSignalingPresent = 23,
            SegmentAttributeXY_adaptiveTimingPresent = 24,
            SegmentAttributeXY_rfSignalRequestPresent = 25,
            SegmentAttributeXY_partialCurbIntrusion = 26,
            SegmentAttributeXY_taperToLeft = 27,
            taperToRight = 28,
            SegmentAttributeXY_taperToCenterLine = 29,
            SegmentAttributeXY_parallelParking = 30,
            SegmentAttributeXY_headInParking = 31,
            SegmentAttributeXY_freeParking = 32,
            SegmentAttributeXY_costToPark = 33,
            SegmentAttributeXY_midBlockCurbPresent = 34,
            SegmentAttributeXY_unEvenPavementPresent = 35
        };
        typedef enum NodeAttributeXY localNode;
        typedef enum SegmentAttributeXY disabled;
        typedef enum SegmentAttributeXY enabled;

        CNodeAttributeSetXY();
        CNodeAttributeSetXY(const CNodeAttributeSetXY&);
        CNodeAttributeSetXY(const localNode&, const disabled&, const enabled&, const CLaneDataAttributeList&,
            unsigned int, unsigned int);

        CNodeAttributeSetXY& operator=(const CNodeAttributeSetXY&);
        int operator==(const CNodeAttributeSetXY&) const;
        int operator!=(const CNodeAttributeSetXY&) const;

        localNode get_localNode() const;
        void set_localNode(const localNode&);

        disabled get_disabled() const;
        void set_disabled(const disabled&);

        enabled get_enabled() const;
        void set_enabled(const enabled&);

        CLaneDataAttributeList get_data() const;
        void set_data(const CLaneDataAttributeList&);

        unsigned int get_dWidth() const;
        void set_dWidth(unsigned int);

        unsigned int get_dElevation() const;
        void set_dElevation(unsigned int);

    private:
        localNode localNode_field;
        disabled disabled_field;
        enabled enabled_field;
        CLaneDataAttributeList data_field;
        unsigned int dWidth_field;
        unsigned int dElevation_field;
    };

} //v2x
} //frame
