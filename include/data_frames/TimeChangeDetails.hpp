#ifndef __TIME_CHANGE_DETAILS_HPP__
#define __TIME_CHANGE_DETAILS_HPP__

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

/*
 * The TimeChangeDetails data frame conveys details about the timing of a phase
 * within a movement.
 *
 * TimeChangeDetails ::= SEQUENCE {
 *      startTime  TimeMark     OPTIONAL,
 *      minEndTime TimeMark,
 *      maxEndTime TimeMark     OPTIONAL,
 *      likelyTime TimeMark     OPTIONAL,
 *      confidence TimeIntervalConfidence OPTIONAL,
 *      nextTime   TimeMark     OPTIONAL
 */

namespace v2x{
namespace frame{

using namespace element;

class CTimeChangeDetails
{
public:
    CTimeChangeDetails();
    virtual ~CTimeChangeDetails();
  
    CTimeMark getMinEndTime();
    void setMinEndTime(CTimeMark &time);

private:
    CTimeMark               _startTime; /* n/a */
    CTimeMark               _minEndTime;
    CTimeMark               _maxEndTime; /* n/a and all below */
    CTimeMark               _likelyTime;
    CTimeMark               _nexTime;
    CTimeIntervalConfidence _confidence;
};

} /* v2x */
} /* frame */
#endif /* __TIME_CHANGE_DETAILS_HPP */
