#pragma once

#include <cstdint>
#include <cstddef>
#include <memory>

#include "msg/IV2XMessage.hpp"

class Sender 
{
public:
    virtual unsigned long int send(std::shared_ptr<uint8_t> data, std::size_t size) = 0;
    virtual unsigned long int send(std::shared_ptr<IV2XMessage> msg) = 0;
    virtual ~Sender() {}
};

