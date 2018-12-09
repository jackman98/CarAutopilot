#ifndef CAR_MANAGER_H
#define CAR_MANAGER_H
#include <ASN1Exch.h>
#include <picar.h>

class CarManager
{
public:
    CarManager();

    static CarManager& getInstance() {
        static CarManager instance;
        return instance;
    }

    std::shared_ptr<Picar> picar() const;
    void setPicar(const std::shared_ptr<Picar> &picar);

    std::shared_ptr<v2x::Car> car() const;
    void setCar(const std::shared_ptr<v2x::Car> &car);

    static void processEVAEvent(std::shared_ptr<v2x::EmergencyVehicle>& eCar);

private:
    std::shared_ptr<Picar> m_picar;
    std::shared_ptr<v2x::Car> m_car;
};

#endif // CAR_MANAGER_H
