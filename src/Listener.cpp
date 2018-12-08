#include "Listener.h"

#include <thread>
#include <fstream>
#include "IntersectionGeometryList.h"

static std::function<void()> bsmHandler;
static std::function<void()> mapHandler;
static std::function<void()> spatmHandler;
static std::function<void()> evaHandler;
static std::function<void()> icaHandler;

CIntersectionID currentIntersectionID;
CLaneID currentLaneID;
std::shared_ptr<v2x::MapUpdate> mapUpdateForCurrentIntersection;

extern std::ofstream fout;

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
    mapUpdateForCurrentIntersection = map;

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
    auto intersections = tl->getIntersectionStates();
    for (auto& intersectionStates: intersections) {
        if (intersectionStates->getIntersectionReferenceID().getIntersectionID() == currentIntersectionID) {
            auto enabledLaneList = intersectionStates->getEnabledLaneList();
                    for (auto& enabledLane: enabledLaneList) {
                        if (enabledLane == currentLaneID) {
                            auto movementEvents = intersectionStates->getMovementEventsFoLane(currentLaneID);
                            auto state = movementEvents.at(0)->getMovementPhaseState();

                            if (state == eMovementPhaseState_t::protectedMovementAllowed) {
                                //TODO: Make a maneuver
                            }

                            if (state == eMovementPhaseState_t::stopAndRemain) {
                                //TODO: Wait for the green signal
                            }
                        }
                    }
        }
    }
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

void setMAPHandler(std::function<void ()> handler)
{
    mapHandler = handler;
}

void setSPATMHandler(std::function<void ()> handler)
{
    spatmHandler = handler;
}

void setEVAHandler(std::function<void ()> handler)
{
    evaHandler = handler;
}

void setICAHandler(std::function<void ()> handler)
{
    icaHandler = handler;
}
