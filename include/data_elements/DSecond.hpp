#ifndef __DSECOND_HPP__
#define __DSECOND_HPP__

#include "DSecond.h"

/*
 * Expresses the number of elapsed minutes of the current year in the time system
 * being used (typically UTC time). Indicate when the message was created.
 *
 * INTEGER ( 0 .. 527040 )
 * -- 527040 - indicates invalid value
 */

namespace v2x {
namespace element {

class CDSecond
{
public:
    CDSecond();
    CDSecond(const DSecond_t& value);
    virtual ~CDSecond();

    DSecond_t get();
    void set(const DSecond_t& value);

    CDSecond& operator=(const DSecond_t& rhs);

private:
    DSecond_t _dsecond;
};

} /* v2x */
} /* element */
#endif /* __DSECOND_HPP__ */
