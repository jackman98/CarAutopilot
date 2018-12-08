#ifndef __MINUTE_OF_THE_YEAR_HPP__
#define __MINUTE_OF_THE_YEAR_HPP__

#include "MinuteOfTheYear.h"

/*
 * Expresses the number of elapsed minutes of the current year in the time system
 * being used (typically UTC time). Indicate when the message was created.
 *
 * INTEGER ( 0 .. 527040 )
 * -- 527040 - indicates invalid value
 */

namespace v2x {
namespace element {

class CMinuteOfTheYear
{
public:
    CMinuteOfTheYear();
    CMinuteOfTheYear(const MinuteOfTheYear_t &value);
    virtual ~CMinuteOfTheYear();

    MinuteOfTheYear_t get() const;
    void set(const MinuteOfTheYear_t& value);

    CMinuteOfTheYear& operator=(CMinuteOfTheYear &rhs);
    CMinuteOfTheYear& operator=(MinuteOfTheYear_t& rhs);

private:
    MinuteOfTheYear_t _moty = 0;
};

} /* v2x */
} /* element */
#endif /* __MINUTE_OF_THE_YEAR_HPP__ */
