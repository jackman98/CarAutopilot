#ifndef __LINE_CONNECTION_ID_HPP__
#define __LINE_CONNECTION_ID_HPP__

#include "LaneConnectionID.h"

/*
 * The LaneConnectionID data entry is used to state a connection index for a 
 * lane to lane connection. It is used to relate this connection between the
 * lane (defined in the MAP) and any dynamic clearance data sent in the SPAT.
 *
 * INTEGER ( 0 .. 255 )
 */

namespace v2x {
namespace element {

class CLaneConnectionID
{
public:
    CLaneConnectionID();
    CLaneConnectionID(const LaneConnectionID_t& value);
    virtual ~CLaneConnectionID();

    CLaneConnectionID get() const;
    void set(const LaneConnectionID_t& value);

    CLaneConnectionID& operator=(const CLaneConnectionID& rhs);
    CLaneConnectionID& operator=(const LaneConnectionID_t& rhs);
    int operator==(const CLaneConnectionID&) const;
    int operator!=(const CLaneConnectionID&) const;

private:
    LaneConnectionID_t _lane_con_id;
};

} /* v2x */
} /* element */
#endif /* __LINE_CONNECTION_ID_HPP__ */
