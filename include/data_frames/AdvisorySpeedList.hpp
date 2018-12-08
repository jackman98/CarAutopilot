#ifndef __ADVISORY_SPEED_LIST_HPP__
#define __ADVISORY_SPEED_LIST_HPP__

#include "V2XTypes.hpp"
#include "V2XEnums.hpp"

#include <list>
#include "AdvisorySpeed.hpp"
/*
 *
 * RepresentingdvisorySpeed data frame is used to convey a recommended
 * traveling approach speed to an intersection from the message issuer to
 * various travelers and vehicle types. Besides support for various
 * eco-driving applications, this allows transmitting recommended speeds for 
 * specialty vehicles such as transit buses.
 *
 * AdvisorySpeedList ::= SEQUENCE (SIZE(1..16)) OF AdvisorySpeed
 *
 */

namespace v2x{
namespace frame{

using namespace element;

class CAdvisorySpeedList
{
public:
    CAdvisorySpeedList();
    CAdvisorySpeedList(std::list<CAdvisorySpeed>& list);    
    virtual ~CAdvisorySpeedList();

private:
    std::list<CAdvisorySpeed> _list;
};

} /* v2x */
} /* frame */
#endif /* __ADVISORY_SPEED_LIST_HPP */
