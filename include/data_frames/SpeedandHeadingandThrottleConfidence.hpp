#ifndef SPEEDANDHEADINGANDTHROTTLECONFIDENCE_HPP
#define SPEEDANDHEADINGANDTHROTTLECONFIDENCE_HPP

#pragma once

#include <string.h>

// #include "data_elements/GlobalEnums.hpp"
#include "GlobalPrimitives.hpp"

namespace v2x {
namespace frame {

class OSS_PUBLIC CSpeedandHeadingandThrottleConfidence   /* SEQUENCE */
{
public:
    CSpeedandHeadingandThrottleConfidence();
    CSpeedandHeadingandThrottleConfidence(const CSpeedandHeadingandThrottleConfidence &);
    CSpeedandHeadingandThrottleConfidence(element::HeadingConfidence_t, element::SpeedConfidence_t, element::ThrottleConfidence_t);
    ~CSpeedandHeadingandThrottleConfidence();

    CSpeedandHeadingandThrottleConfidence & operator = (const CSpeedandHeadingandThrottleConfidence &);
    int operator == (const CSpeedandHeadingandThrottleConfidence &) const;
    int operator != (const CSpeedandHeadingandThrottleConfidence &) const;

    element::HeadingConfidence_t & get_heading();
    element::HeadingConfidence_t get_heading() const;
    void set_heading(element::HeadingConfidence_t);

    element::SpeedConfidence_t & get_speed();
    element::SpeedConfidence_t get_speed() const;
    void set_speed(element::SpeedConfidence_t);

    element::ThrottleConfidence_t & get_throttle();
    element::ThrottleConfidence_t get_throttle() const;
    void set_throttle(element::ThrottleConfidence_t);
private:
    element::HeadingConfidence_t heading_field;
    element::SpeedConfidence_t speed_field;
    element::ThrottleConfidence_t throttle_field;
};

};
};

#endif
