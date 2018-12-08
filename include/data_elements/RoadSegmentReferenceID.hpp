#pragma once

namespace v2x {
namespace element {

/*
 * CReferenceID is used for IntersectionReferenceID and RoadSegmentReferenceID
 */

    class CRoadSegmentReferenceID {
    public:
        CRoadSegmentReferenceID();
        CRoadSegmentReferenceID(const CRoadSegmentReferenceID&);
        CRoadSegmentReferenceID(unsigned int, unsigned int);
        CRoadSegmentReferenceID(unsigned int);

        CRoadSegmentReferenceID& operator=(const CRoadSegmentReferenceID&);
        int operator==(const CRoadSegmentReferenceID&) const;
        int operator!=(const CRoadSegmentReferenceID&) const;
        bool operator<(const CRoadSegmentReferenceID&) const;

        unsigned int get_region() const;
        void set_region(unsigned int);

        unsigned int get_id() const;
        void set_id(unsigned int);

    private:
        unsigned int region_field;
        unsigned int id_field;
    };

} //v2x
} //element
