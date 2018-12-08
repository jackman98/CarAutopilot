#ifndef BSM_MESSAGE_HPP__
#define BSM_MESSAGE_HPP__

#include <memory>
#include <cstdint>
#include <cstddef>
#include "MessageFrame.h"
#include "V2XDataSource.hpp"
#include "IV2XMessage.hpp"

// The basic safety message (BSM) is used in a variety
// of applications to exchange safety data regarding vehicle state.
// This message is broadcast frequently to surrounding
// vehicles with data content as required by safety
// and other applications. Transmission rates are beyond
// the scope of this standard, but a rate 10 times per second
// is typical when congestion control algorithms
// do not prescribe a reduced rate.
// Part I data shall be included in every BSM.
// Part II data items are optional for a given BSM
// and are included as needed according to policies that are
// beyond the scope of this standard.
// A BSM without Part II optional content is a valid message.

class BSMMessage: public IV2XMessage {
public:
    BSMMessage();
    virtual ~BSMMessage();

    void setV2XParams(const std::shared_ptr<V2XDataSource> src);
    void getV2XParams(std::shared_ptr<V2XDataSource> dest);

    virtual void setMessageFrame(std::shared_ptr<MessageFrame_t> frame) override;
    virtual std::shared_ptr<MessageFrame_t> getMessageFrame() override;
    virtual V2XMessageType getType() override {
        return V2XMessageType::BSM;
    }

private:
    uint32_t getBSMCount();
    void fillASNBrakeStatus(const std::shared_ptr<V2XDataSource> src);
    int getBytesOccupied(const std::vector<bool> &vec);
    int getBitsUnused(const std::vector<bool> &vec);

private:
    std::shared_ptr<MessageFrame_t> messageFrame_;
    uint8_t brakesBuf_ = 0;
    uint32_t msgCount_ = 0;

};

#endif
