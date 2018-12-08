#ifndef __INTERSECTION_STATE_OBJECT_HPP__
#define __INTERSECTION_STATE_OBJECT_HPP__

#include "IntersectionStatusObject.h"
#include "CBitString.hpp"

/*
 * Contains Advanced Traffic Controller (ATC)
 *
 * BIT STRING { 0 .. 13 } SIZE(16) )
 *
 * 14, 15 - bits are reserved and must be 0
 */

namespace v2x {
namespace element {

class CIntersectionStatusObject
{
public:
    CIntersectionStatusObject();
    CIntersectionStatusObject(const CBitString &value);
    CIntersectionStatusObject(uint32_t value);
    virtual ~CIntersectionStatusObject();

    void getAsnBitString(BIT_STRING_t *bitString);
    void AsnBitString2Status(BIT_STRING_t *bitString);
    CBitString& get();
    
    CIntersectionStatusObject& operator=(CIntersectionStatusObject &rhs);

private:
    CBitString status;
};

} /* v2x */
} /* element */
#endif /* __INTERSECTION_STATE_OBJECT_HPP__ */
