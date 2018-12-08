#ifndef __SIGNAL_GROUP_ID_HPP__
#define __SIGNAL_GROUP_ID_HPP__

#include "SignalGroupID.h"

/*
 * The SignalGroupID is an index used to map between the internal state machine
 * of one or more signal controllers (or other types of traffic flow devices) 
 * and a common numbering system that can represent all possible combinations
 *  of active  states (movements and phases in US traffic terminology)
 * 
 * SignalGroupID ::= INTEGER (0..255)
 * -- The value 0 shall be used when the ID is
 * -- not available or not known
 * -- the value 255 is reserved to indicate a
 * -- permanent green movement state
 * -- therefore a simple 8 phase signal controller
 * -- device might use 1..9 as its groupIDs
 */

namespace v2x {
namespace element {

class CSignalGroupID
{
public:
    CSignalGroupID();
    CSignalGroupID(const SignalGroupID_t& value);
    virtual ~CSignalGroupID();

    SignalGroupID_t get();
    void set(const SignalGroupID_t& value);

    CSignalGroupID& operator=(const SignalGroupID_t& rhs);
    int operator==(const CSignalGroupID&) const;
    int operator!=(const CSignalGroupID&) const;

private:
    SignalGroupID_t _signal_group_id;
};

} /* v2x */
} /* element */
#endif /* __SIGNAL_GROUP_ID_HPP__ */
