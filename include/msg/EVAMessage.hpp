#ifndef EVA_MESSAGE_HPP__
#define EVA_MESSAGE_HPP__

#include <memory>
#include <cstdint>
#include <cstddef>
#include "MessageFrame.h"
#include "V2XDataSource.hpp"
#include "IV2XMessage.hpp"

class EVAMessage: public IV2XMessage {
public:
    EVAMessage();
    virtual ~EVAMessage() override;

    void setV2XParams(const std::shared_ptr<V2XDataSource> src);
    void getV2XParams(std::shared_ptr<V2XDataSource> dest);

    virtual void setMessageFrame(std::shared_ptr<MessageFrame_t> frame) override;
    virtual std::shared_ptr<MessageFrame_t> getMessageFrame() override;
    virtual V2XMessageType getType() override {
        return V2XMessageType::EVA;
    }

private:
    uint8_t getEVACount();

private:
    std::shared_ptr<MessageFrame_t> messageFrame_;
    uint8_t msgCount_ = 0;
    TemporaryID_t tempId_;
    VehicleType_t vtype_;
    struct FullPositionVector position_;
    Heading_t heading_;
    Elevation_t	elevation_;
    struct TransmissionAndSpeed	speed_;
	struct PositionAccuracy	posAccuracy_;
};

#endif
