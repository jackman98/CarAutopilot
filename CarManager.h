#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H
#include <ASN1Exch.h>
#include <picar.h>
#include "Listener.h"

class CarManager
{
public:
    CarManager(std::shared_ptr<Picar> picar);

    Longitude_t longitude() const;
    void setLongitude(const Longitude_t &longitude);

    Latitude_t latitude() const;
    void setLatitude(const Latitude_t &latitude);

    std::shared_ptr<Picar> picar() const;

private:
    Longitude_t m_longitude;
    Latitude_t m_latitude;

    std::shared_ptr<Picar> m_picar;
};

#endif // CAR_MANAGER_H
