#include "Listener.h"

#include <thread>
#include <fstream>
#include <functional>
#include "IntersectionGeometryList.h"

static std::function<void()> bsmHandler;
static std::function<void()> icaHandler;

extern std::fstream fout;

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

    fout << "BSM msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed << std::endl;
    bsmHandler();
}

void onMAPMessageReceived(std::shared_ptr<v2x::MapUpdate> map)
{
    CIntersectionID intersectionID = map->getIntersectionGeometryLists().front()->get_id().getIntersectionID();
    auto lanes = map->getIntersectionGeometryLists().front()->get_laneSet();
    for (const auto& lane: lanes) {
        fout << "LaneID: " << lane->get_laneID().get();
    }

    fout << "MAP msg received intersecCount=" << map->getIntersectionGeometryLists().size() << std::endl;
    fout << "intersectionID=" << intersectionID.get() << std::endl;
    fout << "MAP msg received intersecCount=" << map->getIntersectionGeometryLists().size() << std::endl;
    fout << "MAP msg received intersecCount=" << map->getIntersectionGeometryLists().size() << std::endl;

}

void onSPATMessageReceived(std::shared_ptr<v2x::TrafficLightStatus> tl)
{
    // TODO
    fout << "TrafficLight msg received, (state1)id=" << (long)tl->getIntersectionState(0)->getIntersectionReferenceID().getIntersectionID().get()
              << ", statesCnt=" << tl->getIntersectionStates().size() << std::endl;
}

void onEVAMessageReceived(std::shared_ptr<v2x::EmergencyVehicle> eCar)
{
    CTempId tId = eCar->getTempId();
    long lat = static_cast<long>(eCar->getLatitude());
    long lon = static_cast<long>(eCar->getLongitude());
    long speed = static_cast<long>(eCar->getSpeed());

    fout << "EVA msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed << std::endl;
}

void onICAMessageReceived(std::shared_ptr<v2x::IntersectionCollisionAvoidance> icCar)
{
    CIntersectionID intersecId = icCar->getCIntersectionReferenceID().getIntersectionID().get();
    v2x::Car car = icCar->getBSMCoreData();
    CTempId tId = car.getTempId();
    long lat = static_cast<long>(car.getLatitude());
    long lon = static_cast<long>(car.getLongitude());
    long speed = static_cast<long>(car.getSpeed());

    fout << "ICA msg received id=" << tId.toString().c_str() << " lat=" << lat << " lon=" << lon << " speed=" << speed
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
