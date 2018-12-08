#ifndef __ENABLED_LANE_LIST_HPP__
#define __ENABLED_LANE_LIST_HPP__

/*
 * The Enabled Lane List data frame is a sequence of lane IDs for lane objects
 * that are activated in the current map configuration.
 *
 * EnabledLaneList ::= SEQUENCE (SIZE(1..16)) OF LaneID 
 *
 */

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include <list>

#include "MovementEvent.hpp"

namespace v2x{
namespace frame{

using namespace element;
class CEnabledLaneList
{
public:
    CEnabledLaneList();
    CEnabledLaneList(std::list<CLaneID>& list);    
    virtual ~CEnabledLaneList();

private:
    std::list<CLaneID> _list;
};

} /* v2x */
} /* frame */
#endif /* __ENABLED_LANE_LIST_HPP__ */
