#ifndef __LANE_ID_HPP__
#define __LANE_ID_HPP__

#include "LaneID.h"

/*
 * Conveyes an assigned index that is unique within an intersecion 
 *
 * INTEGER ( 0 .. 255 )
 * -- 0   - unused or unknown lane ID
 * -- 255 - reserved for future use 
 */

namespace v2x {
namespace element {

class CLaneID
{
public:
    CLaneID();
    CLaneID(const LaneID_t& value);
    virtual ~CLaneID();

    LaneID_t get();
    void set(const LaneID_t& value);

    CLaneID& operator=(const LaneID_t& rhs);
    int operator==(const CLaneID&) const;
    int operator!=(const CLaneID&) const;
    int operator<(const CLaneID&) const;

private:
    LaneID_t _lane_id;
};

} /* v2x */
} /* element */
#endif /* __LANE_ID_HPP__ */
