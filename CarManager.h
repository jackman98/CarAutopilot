#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H
#include <ASN1Exch.h>
#include <picar.h>
#include "Listener.h"

class CarManager
{
public:
    CarManager(std::shared_ptr<Picar> picar);

    std::shared_ptr<Picar> picar() const;

    std::shared_ptr<v2x::Car> car() const;
    void setCar(const std::shared_ptr<v2x::Car> &car);

private:
    std::shared_ptr<Picar> m_picar;
    std::shared_ptr<v2x::Car> m_car;
};

#endif // CAR_MANAGER_H
