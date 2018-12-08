#pragma once

#include <cstdint>
#include <cstddef>
#include <memory>

#include "Sender.hpp"


namespace v2x {

class V2XSender : public Sender
{
public:
    V2XSender();
    virtual ~V2XSender() override;

    unsigned long int send(std::shared_ptr<uint8_t> data, size_t size) override;
    unsigned long int send(std::shared_ptr<IV2XMessage> msg) override;
};

} //v2x
