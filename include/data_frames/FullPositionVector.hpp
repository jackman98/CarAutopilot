#ifndef FULLPOSITIONVECTOR_HPP
#define FULLPOSITIONVECTOR_HPP

#pragma once

#include <string>

#include "GlobalPrimitives.hpp"
#include "data_elements/Latitude.hpp"
#include "data_elements/Longitude.hpp"
#include "data_elements/Elevation.hpp"

#include "DDateTime.hpp"
#include "TransmissionAndSpeed.hpp"
#include "PositionAccuracy.hpp"
#include "PositionConfidenceSet.hpp"
#include "SpeedandHeadingandThrottleConfidence.hpp"

namespace v2x {
namespace frame {

typedef CDDateTime utcTime;

class OSS_PUBLIC CFullPositionVector   /* SEQUENCE */
{
public:
    CFullPositionVector();
    CFullPositionVector(const CFullPositionVector &);
    CFullPositionVector(const CDDateTime &,
                        v2x::element::CLongitude,
                        v2x::element::CLatitude,
                        v2x::element::CElevation,
                        element::heading,
                        const CTransmissionAndSpeed &,
                        const CPositionAccuracy &,
                        element::TimeConfidence_t,
                        const CPositionConfidenceSet &,
                        const CSpeedandHeadingandThrottleConfidence &);

    CFullPositionVector(v2x::element::CLongitude, v2x::element::CLatitude);

    CFullPositionVector & operator = (const CFullPositionVector &);
    // int operator == (const CFullPositionVector &) const;
    // int operator != (const CFullPositionVector &) const;

    CDDateTime *get_utcTime();
    const CDDateTime *get_utcTime() const;
    void set_utcTime(const CDDateTime &);
    int utcTime_is_present() const;
    void omit_utcTime();

    v2x::element::CLongitude & get_CLongitude();
    v2x::element::CLongitude get_CLongitude() const;
    void set_CLongitude(v2x::element::CLongitude);

    v2x::element::CLatitude & get_lat();
    v2x::element::CLatitude get_lat() const;
    void set_lat(v2x::element::CLatitude);

    v2x::element::CElevation *get_elevation();
    const v2x::element::CElevation *get_elevation() const;
    void set_elevation(v2x::element::CElevation);
    int elevation_is_present() const;
    void omit_elevation();

    element::heading *get_heading();
    const element::heading *get_heading() const;
    void set_heading(element::heading);
    int heading_is_present() const;
    void omit_heading();

    CTransmissionAndSpeed *get_speed();
    const CTransmissionAndSpeed *get_speed() const;
    void set_speed(const CTransmissionAndSpeed &);
    int speed_is_present() const;
    void omit_speed();

    CPositionAccuracy *get_posAccuracy();
    const CPositionAccuracy *get_posAccuracy() const;
    void set_posAccuracy(const CPositionAccuracy &);
    int posAccuracy_is_present() const;
    void omit_posAccuracy();

    element::TimeConfidence_t *get_timeConfidence();
    const element::TimeConfidence_t *get_timeConfidence() const;
    void set_timeConfidence(element::TimeConfidence_t);
    int timeConfidence_is_present() const;
    void omit_timeConfidence();

    CPositionConfidenceSet *get_posConfidence();
    const CPositionConfidenceSet *get_posConfidence() const;
    void set_posConfidence(const CPositionConfidenceSet &);
    int posConfidence_is_present() const;
    void omit_posConfidence();

    CSpeedandHeadingandThrottleConfidence *get_speedConfidence();
    const CSpeedandHeadingandThrottleConfidence *get_speedConfidence() const;
    void set_speedConfidence(const CSpeedandHeadingandThrottleConfidence &);
    int speedConfidence_is_present() const;
    void omit_speedConfidence();
private:
    uint32_t bit_mask = 0;
    CDDateTime utcTime_field;
    v2x::element::CLongitude FullPositionVector_longtitude_field;
    v2x::element::CLatitude FullPositionVector_latitude_field;
    v2x::element::CElevation elevation_field;
    element::heading heading_field = 0;
    CTransmissionAndSpeed speed_field;
    CPositionAccuracy posAccuracy_field;
    element::TimeConfidence_t timeConfidence_field;
    CPositionConfidenceSet posConfidence_field;
    CSpeedandHeadingandThrottleConfidence speedConfidence_field;
};
}; //v2x
}; //frame

#endif
