#ifndef __RESTRICTION_CLASS_ID_HPP__
#define __RESTRICTION_CLASS_ID_HPP__

#include "RestrictionClassID.h"

/*
 * The DE_RestrictionClass data element defines an intersection-unique value
 * to convey data about classes of users.
 *
 * RestrictionClassID ::= INTEGER (0..255)
 * -- An index value to identify data about classes of users
 * -- the value used varies with each intersection's
 * -- needs and is defined in the map to the assigned
 * -- classes of supported users.
 */

namespace v2x {
namespace element {

class CRestrictionClassID
{
public:
    CRestrictionClassID();
    CRestrictionClassID(const RestrictionClassID_t& value);
    virtual ~CRestrictionClassID();

    CRestrictionClassID get();
    void set(const RestrictionClassID_t& value);

    CRestrictionClassID& operator=(const RestrictionClassID_t& rhs);
    int operator==(const CRestrictionClassID&) const;
    int operator!=(const CRestrictionClassID&) const;

private:
    RestrictionClassID_t _restriction_class_id;
};

} /* v2x */
} /* element */
#endif /* __RESTRICTION_CLASS_ID_HPP__ */
