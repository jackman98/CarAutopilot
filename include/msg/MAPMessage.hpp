#pragma once

#include "DSRCmsgIDType.h"
#include <memory>
#include <cstdint>
#include <cstddef>
#include "MapUpdate.hpp"

// The MapData message is used to convey many types of geographic road information. At the current time its primary
// use is to convey one or more intersection lane geometry maps within a single message. The map message content
// includes such items as complex intersection descriptions, road segment descriptions, high speed curve outlines (used in
// curve safety messages), and segments of roadway (used in some safety applications). A given single MapData message
// may convey descriptions of one or more geographic areas or intersections. The contents of this message involve defining
// the details of indexing systems that are in turn used by other messages to relate additional information (for example, the
// signal phase and timing via the SPAT message) to events at specific geographic locations on the roadway.

namespace v2x {
namespace msg {

class StringConverter {
public:
    static std::string getStringFromOctet(const OCTET_STRING *str) {
        return str ? getStringFromOctet(*str) : "";
    }

    static std::string getStringFromOctet(const OCTET_STRING &str) {
        if(str.buf && str.size) {
            std::string result;
            result.append(reinterpret_cast<char*>(str.buf), str.size * sizeof(uint8_t));
            return result;
        } else {
            return "";
        }
    }

    static void setOctetString(const std::string &src, OCTET_STRING *dst) {
        if(!dst->buf) {
            dst->buf = reinterpret_cast<uint8_t *>(calloc(src.length(), sizeof(uint8_t)));
        } else {
            dst->buf = reinterpret_cast<uint8_t *>(realloc(dst->buf, src.length() * sizeof(uint8_t)));
        }
        memcpy(dst->buf, src.c_str(), sizeof(uint8_t) * src.length());
        dst->size = src.length();
    }
};

class MAPMessage: public IV2XMessage {
public:
    MAPMessage();
    virtual ~MAPMessage() override;

    void setV2XParams(const std::shared_ptr<MAPDataSource> src);
    void getV2XParams(std::shared_ptr<MAPDataSource> dest);

    virtual void setMessageFrame(std::shared_ptr<MessageFrame_t> frame) override;
    virtual std::shared_ptr<MessageFrame_t> getMessageFrame() override;

    virtual V2XMessageType getType() override {
        return V2XMessageType::MAP;
    }

private:
    void fillIntersection(IntersectionGeometry_t* asnIntersec, std::shared_ptr<frame::CIntersection> intersec);
    void fillGenericLane(GenericLane_t* asnLane, std::shared_ptr<frame::CGenericLane> lane);

private:
    std::shared_ptr<MessageFrame_t> messageFrame_;
    uint32_t msgCount_ = 0;

};

} // namespace msg
} // namespace v2x
