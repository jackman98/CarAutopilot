#pragma once

#include <vector>
#include "RegulatorySpeedLimit.hpp"
namespace v2x {
namespace frame {

    class CLaneDataAttribute;
    typedef std::vector<CLaneDataAttribute> CLaneDataAttributeList;

    class CLaneDataAttribute {
    public:
        enum Id {
            unselected,
            pathEndPointAngle_chosen = 1,
            laneCrownPointCenter_chosen = 2,
            laneCrownPointLeft_chosen = 3,
            laneCrownPointRight_chosen = 4,
            laneAngle_chosen = 5,
            speedLimits_chosen = 6
        };

        CLaneDataAttribute();
        CLaneDataAttribute(const CLaneDataAttribute&);

        CLaneDataAttribute& operator=(const CLaneDataAttribute&);
        int operator==(const CLaneDataAttribute&) const;
        int operator!=(const CLaneDataAttribute&) const;

        unsigned int get_pathEndPointAngle() const;
        void set_pathEndPointAngle(unsigned int);

        unsigned int get_laneCrownPointCenter() const;
        void set_laneCrownPointCenter(unsigned int);

        unsigned int get_laneCrownPointLeft() const;
        void set_laneCrownPointLeft(unsigned int);

        unsigned int get_laneCrownPointRight() const;
        void set_laneCrownPointRight(unsigned int);

        unsigned int get_laneAngle() const;
        void set_laneAngle(unsigned int);

        CRegulatorySpeedLimit get_speedLimits() const;
        void set_speedLimits(const CRegulatorySpeedLimit&);

    private:
        //TODO: add union when apper problem with low memory
        unsigned int pathEndPointAngle_field;
        unsigned int laneCrownPointCenter_field;
        unsigned int laneCrownPointLeft_field;
        unsigned int laneCrownPointRight_field;
        unsigned int laneAngle_field;
        CRegulatorySpeedLimit speedLimits_field;
    };

} //v2x
} //frame