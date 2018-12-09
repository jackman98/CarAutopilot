#include "Listener.h"
#include <chrono>
#include <thread>
#include <fstream>
#include "IntersectionGeometryList.h"
#include "Map.h"

static BsmHandler bsmHandler;
static MapHandler mapHandler;
static SpatmHandler spatmHandler;
static EvaHandler evaHandler;
static IcaHandler icaHandler;

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
    CIntersectionID intersectionID = map->getIntersectionGeometryLists().front()->get_id().getIntersectionID();
    if (intersectionID == currentIntersectionID) {
        mapUpdateForCurrentIntersection = map;
    }

    auto lanes = map->getIntersectionGeometryLists().front()->get_laneSet();
    for (const auto& lane: lanes) {
        fout << "LaneID: " << lane->get_laneID().get();
    }

    fout << "MAP msg received intersecCount=" << map->getIntersectionGeometryLists().size() << std::endl;
    fout << "intersectionID=" << intersectionID.get() << std::endl;
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
                                long waitTime = static_cast<long>(movementEvents.at(0)->getMinEndTime().get());
                                std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
                                //TODO: Make a maneuver
                            }
                        }
                    }
        }
    }
}

void onEVAMessageReceived(std::shared_ptr<v2x::EmergencyVehicle> eCar)
{
    evaHandler(eCar);
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

void setBSMHandler(BsmHandler handler)
{
    bsmHandler = handler;
}

void setMAPHandler(MapHandler handler)
{
    mapHandler = handler;
}

void setSPATMHandler(SpatmHandler handler)
{
    spatmHandler = handler;
}

void setEVAHandler(EvaHandler handler)
{
    evaHandler = handler;
}

void setICAHandler(IcaHandler handler)
{
    icaHandler = handler;
}
