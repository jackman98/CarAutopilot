#ifndef __ZONE_LENGTH_HPP__
#define __ZONE_LENGTH_HPP__

#include "ZoneLength.h"

/*
 * Data element is used to provide an estimated distance from the stop bar, 
 * along the lane centerline back in the lane to which it pertains.
*
 * ZoneLength ::= INTEGER (0..10000)
 * -- Unit = 1 meter, 0 = unknown,
 * -- The value 10000 to be used for Distances >=10000 m
 * -- (e.g. from known point to another point along a
 * -- known path, often against traffic flow direction
 * -- when used for measuring queues)
 */

namespace v2x {
namespace element {

class CZoneLength
{
public:
    CZoneLength();
    CZoneLength(const ZoneLength_t& value);
    virtual ~CZoneLength();

    CZoneLength get();
    void set(const ZoneLength_t& value);

    CZoneLength& operator=(const ZoneLength_t& rhs);

private:
    ZoneLength_t _zone_length;
};

} /* v2x */
} /* element */
#endif /* __ZONE_LENGTH_HPP__ */
