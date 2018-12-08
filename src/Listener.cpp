#include "Listener.h"

#include <thread>
#include <functional>

static std::function<void()> bsmHandler;
static std::function<void()> icaHandler;

void setupSubscriptions()
{
    std::thread([] {
        subscribeBSM(onBSMMessageReceived);
    }).detach();

    std::thread([] {
        subscribeMAP(onMAPMessageReceived);
    }).detach();

    std::thread([] {
        subscribeSPAT(onSPATMessageReceived);
    }).detach();

    std::thread([] {
        subscribeEVA(onEVAMessageReceived);
    }).detach();

    std::thread([] {
        subscribeICA(onICAMessageReceived);
    }).detach();
}

void dropSubscriptions()
{
    // TODO
}

void onBSMMessageReceived(std::shared_ptr<v2x::Car> car)
{
    CTempId tId = car->getTempId();
    long lat = static_cast<long>(car->getLatitude());
    long lon = static_cast<long>(car->getLongitude());
    long speed = static_cast<long>(car->getSpeed());

    std::cout << "BSM msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed << std::endl;
    bsmHandler();
}

void onMAPMessageReceived(std::shared_ptr<v2x::MapUpdate> map)
{
    // TODO
    std::cout << "MAP msg received intersecCnt=" << map->getIntersectionGeometryLists().size() << std::endl;
}

void onSPATMessageReceived(std::shared_ptr<v2x::TrafficLightStatus> tl)
{
    // TODO
    std::cout << "TrafficLight msg received, (state1)id=" << (long)tl->getIntersectionState(0)->getIntersectionReferenceID().getIntersectionID().get()
              << ", statesCnt=" << tl->getIntersectionStates().size() << std::endl;
}

void onEVAMessageReceived(std::shared_ptr<v2x::EmergencyVehicle> eCar)
{
    CTempId tId = eCar->getTempId();
    long lat = static_cast<long>(eCar->getLatitude());
    long lon = static_cast<long>(eCar->getLongitude());
    long speed = static_cast<long>(eCar->getSpeed());

    std::cout << "EVA msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed << std::endl;
}

void onICAMessageReceived(std::shared_ptr<v2x::IntersectionCollisionAvoidance> icCar)
{
    CIntersectionID intersecId = icCar->getCIntersectionReferenceID().getIntersectionID().get();
    v2x::Car car = icCar->getBSMCoreData();
    CTempId tId = car.getTempId();
    long lat = static_cast<long>(car.getLatitude());
    long lon = static_cast<long>(car.getLongitude());
    long speed = static_cast<long>(car.getSpeed());

    std::cout << "ICA msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed
              << " intersectionId=" << intersecId.get() << std::endl;
    icaHandler();
}

void setBSMHandler(std::function<void()> handler)
{
    bsmHandler = handler;
}

void setICAHandler(std::function<void ()> handler)
{
    icaHandler = handler;
}
