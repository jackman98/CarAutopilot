#pragma once

#include <memory>
#include <cstdint>
#include <cstddef>
#include "MessageFrame.h"
#include "ICADataSource.hpp"
#include "IV2XMessage.hpp"

// This message is intended to be used to broadcast to other DSRC devces in the area a warning of a potential
// collision with a vehicle that is likely to be entering an intersection without the right of way. The sender may be either an
// equipped vehicle or another source such as the infrastructure.
namespace v2x {
namespace msg {

class ICAMessage: public IV2XMessage {
public:
    ICAMessage();
    virtual ~ICAMessage() override;

    void setV2XParams(const std::shared_ptr<ICADataSource> src);
    void getV2XParams(std::shared_ptr<ICADataSource> dest);

    virtual void setMessageFrame(std::shared_ptr<MessageFrame_t> frame) override;
    virtual std::shared_ptr<MessageFrame_t> getMessageFrame() override;
    virtual V2XMessageType getType() override {
        return V2XMessageType::ICA;
    }

private:
    uint32_t getICACount();
    void fillASNBrakeStatus(const std::shared_ptr<ICADataSource> src);
    void fillASNVehicleEvent(const std::shared_ptr<ICADataSource> src);
    int getBytesOccupied(const std::vector<bool> &vec);
    //int getVehicle(const std::vector<bool> &vec);
    int getBitsUnused(const std::vector<bool> &vec);
    //void fillVehicleEvent(const std::vector<bool> &vec);
    std::shared_ptr<MessageFrame_t> messageFrame_;

    uint8_t brakesBuf_ = 0;
    uint32_t msgCount_ = 0;
};


} // namespace msg
} // namespace v2x
