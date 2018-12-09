#include "Map.h"
#include <cmath>
#include <algorithm>
#include <climits>
#include <iostream>

struct Vec2
{
    Vec2() = default;
    Vec2(double x, double y) { this->x = x; this->y = y; }
    explicit Vec2(Position position) : x(position.longitude), y(position.latitude) { }

    Position toPosition() const
    {
        Position pos{};
        pos.longitude = static_cast<long>(x);
        pos.latitude = static_cast<long>(y);
        return pos;
    }


    Vec2 normalized() const
    {
        double _len = len();
        if (_len <= 0)
        {
            return *this;
        }

        Vec2 result;

        result.x = x / _len;
        result.y = y / _len;
        return result;
    }

    double len() const
    {
        return sqrt(squadLen());
    }

    double squadLen() const
    {
        return x * x + y * y;
    }

    double x = 0.0f;
    double y = 0.0f;
};

Vec2 operator+ (Vec2 const& l, Vec2 const& r)
{
    return {l.x + r.x, l.y + r.y};
}

Vec2 operator- (Vec2 const& l, Vec2 const& r)
{
    return {l.x - r.x, l.y - r.y};
}

Vec2 operator* (Vec2 const& l, double r)
{
    return {l.x * r, l.y * r};
}

double scalarMult(Vec2 const& l, Vec2 const& r)
{
    return l.x * r.x + l.y * r.y;
}

Vec2 projection(Vec2 const& a, Vec2 const& b, Vec2 const& x)
{
    Vec2 v = b - a;
    Vec2 vn = v.normalized();
    double f = scalarMult(vn, x - a);
    return a + vn * f;
}

long Lane::getDistance() const
{
    return static_cast<long>((Vec2(end) - Vec2(begin)).len());
}

std::vector<LocationInfo> Map::whereIs(Position position)
{
    std::vector<LocationInfo> result{};

    // may change to fastest algorithm
    for (auto const& lane : lanes)
    {
        auto distance = distanceToLane(position, lane);
        if (distance.first <= THRESHOLD_POSITION)
        {
            LocationInfo info{ &lane, distance.second };
            result.push_back(info);
        }
    }

    return result;
}

std::vector<Maneuver> Map::calculateRoute(Position from, Position to)
{
    std::vector<Maneuver> result;
    return result;
}

std::pair<long, long> Map::distanceToLane(Position position, Lane const& lane) const
{
    long distance = 0;
    long progress = 0;
    Vec2 p(position), a(lane.begin), b(lane.end);
    Vec2 xp = projection(a, b, p);
    
    double len = (a- b).len();
    double da = (a - xp).len();
    double db = (b - xp).len();  

    if (da > len || db > len)
    {
        double pa = (p - a).len();
        double pb = (p - a).len();
        if (pa < pb)
        {
            distance = static_cast<long>(pa);
            progress = 0; // begin
        }
        else
        {
            distance = static_cast<long>(pb);
            progress = 100; // end
        }
    }
    else
    {
        distance = static_cast<long>((xp - p).len());
        progress = static_cast<long>(da / len * 100);
    }

    return {distance, progress};
}
