#pragma once

#include <vector>
#include "GlobalPrimitives.hpp"

namespace v2x {
namespace frame{
class CVehicleEventFlags {
public:
    CVehicleEventFlags();
    ~CVehicleEventFlags();
    const std::vector<bool> getVehicleEventFlags() const;
    void    setVehicleEventFlags(const std::vector<bool>& value);
private:
    std::vector<bool> vehicleEventFlags_;
};
}
}

