#include "CarManager.h"

CarManager::CarManager(std::shared_ptr<Picar> picar)
{
    m_picar = picar;

    setupSubscriptions();

    setBSMHandler([] () {});
    setICAHandler([] () {});
}

Longitude_t CarManager::longitude() const
{
    return m_longitude;
}

void CarManager::setLongitude(const Longitude_t &longitude)
{
    m_longitude = longitude;
}

Latitude_t CarManager::latitude() const
{
    return m_latitude;
}

void CarManager::setLatitude(const Latitude_t &latitude)
{
    m_latitude = latitude;
}

std::shared_ptr<Picar> CarManager::picar() const
{
    return m_picar;
}
