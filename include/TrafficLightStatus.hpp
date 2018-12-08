#ifndef __TRAFFIC_LIGHT_H__
#define __TRAFFIC_LIGHT_H__

#include "V2XTypes.hpp"
#include "data_frames/IntersectionState.hpp"

namespace v2x {

using namespace v2x::element;
using namespace v2x::frame;


class TrafficLightStatus
{
public:
    TrafficLightStatus();
    TrafficLightStatus(CMinuteOfTheYear &moy, CDescriptiveName &name);

    virtual ~TrafficLightStatus();

    CIntersectionStateList getIntersectionStates() const;
    std::shared_ptr<CIntersectionState> getIntersectionState(unsigned int state_idx);
    unsigned int addIntersectionState(std::shared_ptr<CIntersectionState> state);
    void clearIntersectionStateList();

    CMinuteOfTheYear getMinuteOfTheYear() const;
    void setMinuteOfTheYear(const CMinuteOfTheYear &moy);

    CDescriptiveName getDescriptiveName() const;
    void setDescriptiveName(const CDescriptiveName &name);

private:
    CMinuteOfTheYear _minuteOfTheYear;
    CDescriptiveName _name;
    CIntersectionStateList _intersections;

    const unsigned int _intersectionSizeLimit = 32;
};

} //v2x

#endif /* __TRAFFIC_LIGHT_H__ */
