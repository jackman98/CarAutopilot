#pragma once
#ifndef TRANSMISSIONANDSPEED_HPP
#define TRANSMISSIONANDSPEED_HPP

#include "GlobalPrimitives.hpp"
#include "data_elements/TransmissionState.hpp"
#include <string>

namespace v2x {
namespace frame {

class CTransmissionAndSpeed   // SEQUENCE
{
public:
    //void * operator new(size_t size);
    //void operator delete(void *ptr);

    typedef CTransmissionState transmisson;

    CTransmissionAndSpeed();
    CTransmissionAndSpeed(const CTransmissionAndSpeed &);
    CTransmissionAndSpeed(transmisson, element::speed);

    ~CTransmissionAndSpeed();
    CTransmissionAndSpeed & operator = (const CTransmissionAndSpeed &);
    // int operator == (const CTransmissionAndSpeed &) const;
    // int operator != (const CTransmissionAndSpeed &) const;

    transmisson & get_transmisson();
    transmisson get_transmisson() const;
    void set_transmisson(transmisson);

    element::speed & get_speed();
    element::speed get_speed() const;
    void set_speed(element::speed);
private:
    transmisson transmisson_field;
    element::speed speed_field;
};

};
};

#endif
