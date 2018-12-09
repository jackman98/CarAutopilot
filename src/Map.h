
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
    long longitude;
};

struct Lane 
{
    long id = 0;
    Position begin{}, end{};
    Lane const* parallelLane = nullptr;
    Intersection* source = nullptr;
    Intersection* target = nullptr;
    bool isRight = false;
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
    Intersection const* intersection;
};

struct LocationInfo
{
    Lane const* lane;
    long progress;
};

class Map
{
public:
    Map() = default;

    std::vector<LocationInfo> whereIs(Position position);
    std::vector<Maneuver> calculateRoute(Position from, Position to);

    std::pair<long, long> distanceToLane(Position position, Lane const& lane) const;

    std::vector<Intersection> intersections;
    std::vector<Lane> lanes;

    long const THRESHOLD_POSITION = 10;
};
