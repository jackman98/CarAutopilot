#pragma once

#include <ASN1Exch.h>
#include <functional>

class CarManager;

using BsmHandler = void(*)();
using MapHandler = void(*)();
using SpatmHandler = void(*)();
using EvaHandler = void(*)(std::shared_ptr<v2x::EmergencyVehicle>&);
using IcaHandler = void(*)();

void setupSubscriptions();
void dropSubscriptions();

void onBSMMessageReceived(std::shared_ptr<v2x::Car> car);
void onMAPMessageReceived(std::shared_ptr<v2x::MapUpdate> map);
void onSPATMessageReceived(std::shared_ptr<v2x::TrafficLightStatus> tl);
void onEVAMessageReceived(std::shared_ptr<v2x::EmergencyVehicle> eCar);
void onICAMessageReceived(std::shared_ptr<v2x::IntersectionCollisionAvoidance> icCar);

void setBSMHandler(BsmHandler handler);
void setMAPHandler(MapHandler handler);
void setSPATMHandler(SpatmHandler handler);
void setEVAHandler(EvaHandler handler);
void setICAHandler(IcaHandler handler);
