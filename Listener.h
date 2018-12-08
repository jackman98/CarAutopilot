#pragma once

#include <ASN1Exch.h>
#include <functional>

void setupSubscriptions();
void dropSubscriptions();

void onBSMMessageReceived(std::shared_ptr<v2x::Car> car);
void onMAPMessageReceived(std::shared_ptr<v2x::MapUpdate> map);
void onSPATMessageReceived(std::shared_ptr<v2x::TrafficLightStatus> tl);
void onEVAMessageReceived(std::shared_ptr<v2x::EmergencyVehicle> eCar);
void onICAMessageReceived(std::shared_ptr<v2x::IntersectionCollisionAvoidance> icCar);

void setBSMHandler(std::function<void()> handler);
void setMAPHandler(std::function<void()> handler);
void setSPATMHandler(std::function<void()> handler);
void setEVAHandler(std::function<void()> handler);
void setICAHandler(std::function<void()> handler);
