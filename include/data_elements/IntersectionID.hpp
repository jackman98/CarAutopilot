#ifndef __INTERSECTION_ID_HPP__
#define __INTERSECTION_ID_HPP__

#include "IntersectionID.h"

/*
 * Expresses the number of elapsed minutes of the current year in the time system
 * being used (typically UTC time). Indicate when the message was created.
 *
 * INTEGER ( 0 .. 527040 )
 * -- 527040 - indicates invalid value
 */

namespace v2x {
namespace element {

class CIntersectionID
{
public:
    CIntersectionID();
    CIntersectionID(const IntersectionID_t& value);
    virtual ~CIntersectionID();

    IntersectionID_t get() const;
    void set(const IntersectionID_t& value);

    CIntersectionID& operator=(const IntersectionID_t& rhs);
    CIntersectionID& operator=(const CIntersectionID& rhs);
    int operator==(const CIntersectionID&) const;
    int operator!=(const CIntersectionID&) const;
    int operator<(const CIntersectionID&) const;

private:
    IntersectionID_t _intersection_id;
};

} /* v2x */
} /* element */
#endif /* __INTERSECTION_ID_HPP__ */
