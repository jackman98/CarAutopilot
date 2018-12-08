#ifndef __WAIT_ON_STOP_LINE_HPP__
#define __WAIT_ON_STOP_LINE_HPP__

#include "WaitOnStopLine.h"

/*
 * data element is used to indicate to the vehicle that it must stop at the
 * stop line and not move past.
 *
 * WaitOnStopline ::= BOOLEAN --
 * -- True or False
 * -- If "true", the vehicles on this specific connecting
 * -- maneuver have to stop on the stop-line
 * -- and not to enter the collision area
 */

namespace v2x {
namespace element {

class CWaitOnStopLine
{
public:
    CWaitOnStopLine();
    CWaitOnStopLine(const WaitOnStopLine_t& value);
    virtual ~CWaitOnStopLine();

    CWaitOnStopLine get();
    void set(const WaitOnStopLine_t& value);

    CWaitOnStopLine& operator=(const WaitOnStopLine_t& rhs);

private:
    WaitOnStopLine_t _wait_on_stop_line;
};

} /* v2x */
} /* element */
#endif /* __WAIT_ON_STOP_LINE_HPP__ */
