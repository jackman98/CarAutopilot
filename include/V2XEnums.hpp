#ifndef __V2X_ENUMERATES_HPP__
#define __V2X_ENUMERATES_HPP__

enum CAllowedManeuvers {
    StraightAllowed	        = 0,
    LeftAllowed	            = 1,
    RightAllowed	        = 2,
    UTurnAllowed	        = 3,
    LeftTurnOnRedAllowed	= 4,
    RightTurnOnRedAllowed	= 5,
    LaneChangeAllowed	    = 6,
    NoStoppingAllowed	    = 7,
    yieldAllwaysRequired	= 8,
    goWithHalt	            = 9,
    caution	                = 10,
    reserved1	            = 11
};

typedef enum { /* TODO : discuss? */
    V2X_SUCCESS            = 0,
    V2X_INVALID_FIELD_DATA = 0xFFFF0000,
} V2X_error_t;

typedef enum {
    none        =  0,
    greenwave   =  1,
    ecoDrive    =  2,
    transit     =  3,
} eAdvisorySpeedType_t;

typedef enum {
    unavailable =  0,
    prec100ms   =  1, /*  100 m/s */
    prec10ms    =  2, /*   10 m/s */
    prec5ms     =  3, /*    5 m/s */
    prec0_1ms   =  5, /*  0.1 m/s */
    prec0_05ms  =  6, /* 0.05 m/s */
    prec0_01ms  =  7, /* 0.01 m/s */
} eSpeedConfidence_t;

typedef enum {
    unavailable_mps =  0, /* TODO: */
    dark            =  1, 
    stopThenProceed =  2,           /* RED WITH GREEN ARROW*/
    stopAndRemain   =  3,           /* RED */
    preMovement     =  4,
    permissiveMovementAllowed = 5,  /* GREEN */
    protectedMovementAllowed  = 6,  /* GREEN */
    permissiveClearance       = 7,
    protectedClearance        = 8,
    cautionConflictingTraffic = 9,
} eMovementPhaseState_t;

enum class eVehicleType_t {
    none,
    unknown,
    special,
    moto,
    car,
    carOther,
    bus,
    axleCnt2,
    axleCnt3,
    axleCnt4,
    axleCnt4Trailer,
    axleCnt5Trailer,
    axleCnt6Trailer,
    axleCnt5MultiTrailer,
    axleCnt6MultiTrailer,
    axleCnt7MultiTrailer
};

#endif /* __V2X_ENUMERATES_HPP__ */
