#include "Car.hpp"
#include "EmergencyVehicle.hpp"
#include "MapUpdate.hpp"
#include "TrafficLightStatus.hpp"
#include "IntersectionCollisionAvoidance.hpp"

#include <memory>

#define BSM_LEN 100
#define ICA_LEN 100
#define EVA_LEN 100
#define MAP_LEN 100
#define SPAT_LEN 100

long int sendBSM( std::shared_ptr<v2x::Car> src );
long int sendBSM( v2x::Car *src );
void subscribeBSM( void (*Callback)(std::shared_ptr<v2x::Car>), int len = BSM_LEN);
void unsubscribeBSM(  );

long int sendEVA(std::shared_ptr<v2x::EmergencyVehicle> src );
long int sendEVA(v2x::EmergencyVehicle* src );
void subscribeEVA( void (*Callback)(std::shared_ptr<v2x::EmergencyVehicle>), int len = EVA_LEN);
void unsubscribeEVA(  );

long int sendMAP( std::shared_ptr<v2x::MapUpdate> src );
long int sendMAP( v2x::MapUpdate *src );
void subscribeMAP( void (*Callback)(std::shared_ptr<v2x::MapUpdate>), int len = MAP_LEN);
void unsubscribeMAP(  );

long int sendSPAT( std::shared_ptr<v2x::TrafficLightStatus> src );
long int sendSPAT( v2x::TrafficLightStatus *src );
void subscribeSPAT( void (*Callback)(std::shared_ptr<v2x::TrafficLightStatus>), int len = SPAT_LEN);
void unsubscribeSPAT(  );

long int sendICA( std::shared_ptr<v2x::IntersectionCollisionAvoidance> src );
long int sendICA(v2x::IntersectionCollisionAvoidance *src);
void subscribeICA( void (*Callback)(std::shared_ptr<v2x::IntersectionCollisionAvoidance>), int len = ICA_LEN);
void unsubscribeICA(  );
