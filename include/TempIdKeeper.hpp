#ifndef TEMPIDKEEPER_H__
#define TEMPIDKEEPER_H__

#include "data_elements/TempId.hpp"
#include <vector>
#include <random>

using namespace v2x::element;

class TempIdKeeper
{
public:
    TempIdKeeper(double seedA, double seedB, double seedC, double seedD);
    ~TempIdKeeper();

    const CTempId generateTempId();
    const CTempId getLastTempId();

    bool contains(CTempId);
    void initRandomGenerators(double seedA, double seedB, double seedC, double seedD);

private:
    static const int TEMP_ID_SIZE = 4;//TemporaryID has size 4 according to standard
    static const int TEMP_ID_LIST_MAX_SIZE = 8;

    std::vector<std::minstd_rand*> randomGenerators;
    std::vector<CTempId> tempIdList;
    int countdownToNew = 0;

    int generateCountdownToNew();
    const CTempId generateNewTempId() const;
};

#endif
