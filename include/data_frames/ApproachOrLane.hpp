#pragma once
#include "string.h"

namespace v2x{
namespace frame {

    class CApproachOrLane {
    public:
        enum Id {
            unselected,
            approach_chosen = 1,
            lane_chosen = 2
        };

        typedef unsigned int approach;
        typedef unsigned int lane;

        CApproachOrLane();

        CApproachOrLane(const CApproachOrLane &);

        CApproachOrLane &operator=(const CApproachOrLane &);
        // int operator == (const CApproachOrLane &) const;
        // int operator != (const CApproachOrLane &) const;

        unsigned int get_approach() const;

        // const unsigned int *get_approach() const;
        unsigned int get_lane() const;
        // const unsigned int *get_lane() const;

        void set_approach(unsigned int value);

        void set_lane(unsigned int value);

        ~CApproachOrLane();

    private:
        //TODO add union when apear problwm with memmory
        unsigned int approach_field;
        unsigned int lane_field;
    };

}
}
