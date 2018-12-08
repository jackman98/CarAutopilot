#ifndef __MSG_COUNT_HPP__
#define __MSG_COUNT_HPP__

#include "MsgCount.h"

/*
 * Sequence number of the message within a stream of messages with the same DSRCmsgID and from the same sender
 * 
 * INTEGER ( 0 .. 127 )
 */

namespace v2x {
namespace element {

class CMsgCount
{
public:
    CMsgCount();
    CMsgCount(const MsgCount_t& value);
    virtual ~CMsgCount();

    MsgCount_t get();
    void set(const MsgCount_t& value);

    CMsgCount& operator=(MsgCount_t& rhs);
    CMsgCount& operator=(CMsgCount& rhs);


private:
    MsgCount_t _msg_count;
};

} /* v2x */
} /* element */
#endif /* __MSG_COUNT_HPP__ */
