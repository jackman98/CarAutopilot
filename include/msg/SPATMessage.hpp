#pragma once

#include <memory>
#include <cstdint>
#include <cstddef>
#include "MessageFrame.h"
#include "V2XDataSource.hpp"
#include "IV2XMessage.hpp"

// tmp
#include "TrafficLightStatus.hpp"

namespace v2x {
namespace msg {

class SPATMessage: public IV2XMessage {
public:
    SPATMessage();
    virtual ~SPATMessage() override;

    void setV2XParams(const std::shared_ptr</*V2XDataSource*/TrafficLightStatus> src);
    void getV2XParams(std::shared_ptr</*V2XDataSource*/TrafficLightStatus> dest);

    virtual void setMessageFrame(std::shared_ptr<MessageFrame_t> frame) override;
    virtual std::shared_ptr<MessageFrame_t> getMessageFrame() override;
    virtual V2XMessageType getType() override {
        return V2XMessageType::SPAT;
    }

private:
    uint32_t getSPATCount();

private:
    std::shared_ptr<MessageFrame_t> messageFrame_;
    uint32_t msgCount_ = 0;

};


} // msg
} // v2x
