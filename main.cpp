#include <iostream>
#include <alphabot.h>
#include <picar.h>

#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <stdexcept>
#include <wiringPi.h>
#include "Listener.h"


struct StartData
{
    std::string lane;
    size_t targetIntersection;
};

StartData getStartData();

int main(int argc, char const *argv[])
{
    StartData startData = getStartData();

    wiringPiSetupGpio();
    setupSubscriptions();

    Picar car;
    car.init();

    setBSMHandler([] () {});
    setICAHandler([] () {});

    while (1) {
        try {
            car.runToLine();
            std::cout << "enter crossroads: ";
            char direction;
            std::cin >> direction;
            if(direction == 's' || direction == 'e') {
                car.stop();
                exit(0);
            }
            car.crossroads(static_cast<Picar::eDirection>(direction));
        } catch(...) {
            car.stop();
            exit(-1);
        }
    }

    return 0;
}


StartData getStartData()
{
    StartData out{};
    std::cin >> out.lane;
    std::cin >> out.targetIntersection;
    return out;
}