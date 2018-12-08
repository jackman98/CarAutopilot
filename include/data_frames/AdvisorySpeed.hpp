#ifndef __ADVISORY_SPEED_HPP__
#define __ADVISORY_SPEED_HPP__

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

/*
 * RepresentingdvisorySpeed data frame is used to convey a recommended
 * traveling approach speed to an intersection from the message issuer to
 * various travelers and vehicle types. Besides support for various
 * eco-driving applications, this allows transmitting recommended speeds for 
 * specialty vehicles such as transit buses.
 *
 * AdvisorySpeed ::= SEQUENCE {
 *      type            AdvisorySpeedType,
 *      speed           SpeedAdvice OPTIONAL,
 *      confidence      SpeedConfidence OPTIONAL,
 *      distance        ZoneLength OPTIONAL,
 *      class           RestrictionClassID OPTIONAL,
 *      ------------------------------------------
 *      regional        SEQUENCE (SIZE(1..4)) OF
 *              RegionalExtension {{REGION.Reg-AdvisorySpeed}} OPTIONAL,
 *      ...
 * }
 */

namespace v2x{
namespace frame{

using namespace element;

class CAdvisorySpeed
{
public:
    CAdvisorySpeed();
    CAdvisorySpeed(eAdvisorySpeedType_t type);
    virtual ~CAdvisorySpeed();

private:
    eAdvisorySpeedType_t    _type;
    CSpeedAdvice            _speed;
    eSpeedConfidence_t      _confidence;
    CZoneLength             _distance;
    CRestrictionClassID     _class;

/* TODO: investigate */
#ifdef REGIONAL_EXTENSION_ENABLED   
    CRegionalExtension  _regional;
#endif
};

} /* v2x */
} /* frame */
#endif /* __ADVISORY_SPEED_HPP */
