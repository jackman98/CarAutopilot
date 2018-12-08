
#include <vector>

struct Position;
struct Lane;
struct Intersection;
struct Maneuver;
struct LocationInfo;

enum class ManeuverType : int
{
    FORWARD,
    TURN_RIGHT,
    TURN_LEFT
};

struct Position
{
    long latitude;
    long longtude;
};

struct Lane 
{
    Position begin, end;
    Lane* parallelLane = nullptr;
    Intersection* source = nullptr;
    Intersection* target = nullptr;
};

struct Intersection
{
    long id = 0;
    std::vector<Lane> inLanes;
    std::vector<Lane> outLanes;
};

struct Maneuver
{
    ManeuverType type;
    Intersection* intersection;
};

struct LocationInfo
{
    Lane* lane;
    long progress;
};

struct ManeuverType
{
    std::vector<Intersection*> intersections;
    std::vector<Lane*> lanes;
};

LocationInfo whereIs(Position position);