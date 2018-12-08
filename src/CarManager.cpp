#include "CarManager.h"

CarManager::CarManager(std::shared_ptr<Picar> picar) : m_car(new v2x::Car)
{
    m_picar = picar;

    setupSubscriptions();

    setBSMHandler([] () {});
    setICAHandler([] () {});
}

std::shared_ptr<Picar> CarManager::picar() const
{
    return m_picar;
}

std::shared_ptr<v2x::Car> CarManager::car() const
{
    return m_car;
}

void CarManager::setCar(const std::shared_ptr<v2x::Car> &car)
{
    m_car = car;
}
