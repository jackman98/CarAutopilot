#include "CarManager.h"
#include "Algorithms.hpp"
#include "Listener.h"
#include <fstream>

extern std::ofstream fout;

CarManager::CarManager()
{
    setEVAHandler(CarManager::processEVAEvent);
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

void CarManager::setPicar(const std::shared_ptr<Picar> &picar)
{
    m_picar = picar;
}

void CarManager::processEVAEvent(std::shared_ptr<v2x::EmergencyVehicle>& eCar)
{
    const std::shared_ptr<v2x::Car> myCar = getInstance().car();

//    long myLat = static_cast<long>(myCar->getLatitude());
//    long myLon = static_cast<long>(myCar->getLongitude());
//    long myWidth = static_cast<long>(myCar->getVehicleSize().get().width);
//    long myLength = static_cast<long>(myCar->getVehicleSize().get().length);
//    long mySpeed = static_cast<long>(myCar->getSpeed());
//    long myHeading = static_cast<long>(myCar->getHeading());

//    CTempId tId = eCar->getTempId();
//    long lat = static_cast<long>(eCar->getLatitude());
//    long lon = static_cast<long>(eCar->getLongitude());
//    long width = static_cast<long>(eCar->getVehicleSize().get().width);
//    long length = static_cast<long>(eCar->getVehicleSize().get().length);
//    long speed = static_cast<long>(eCar->getSpeed());
//    long heading = static_cast<long>(eCar->getHeading());

    int angle = 0;

    Algorithms alg;

    std::shared_ptr<v2x::Car> tempCar(dynamic_cast<v2x::Car*>(eCar.get()));

    alg.areCarsCrossing(myCar, tempCar, angle);

//    const int angleError = 15;

//    if ((360 - angleError) < myHeading || myHeading < (0 + angleError)) {

//    }

//    if ((90 - angleError) < myHeading || myHeading < (90 + angleError)) {

//    }

//    if ((180 - angleError) < myHeading || myHeading < (180 + angleError)) {

//    }

//    if ((270 - angleError) < myHeading || myHeading < (270 + angleError)) {

//    }

//    if(a.rb.y>b.lt.y || a.lt.y<b.rb.y || a.lt.x>b.rb.x || a.rb.x<b.lt.x)
//    {
//        cout<<"Прямоугольники не пересекаются"<<endl;
//    }
//    else
//    {
//        c.lt.y=min(a.lt.y,b.lt.y);
//        c.lt.x=max(a.lt.x,b.lt.x);
//        c.rb.y=max(a.rb.y,b.rb.y);
//        c.rb.x=min(a.rb.x,b.rb.x);
//        cout<<"Координаты пересечения:"<<endl;
//        cout<<"левый верхний угол: x = "<<c.lt.x<<"\t y = "<<c.lt.y<<endl;
//        cout<<"правый нижний угол: x = "<<c.rb.x<<"\t y = "<<c.rb.y<<endl;
//    }
}
