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
#include <fstream>
#include "src/UdpLogger.h"

std::ofstream fout;

struct StartData
{
    std::string lane;
    size_t targetIntersection;
};

StartData getStartData();

int main(int argc, char const *argv[])
{
    UdpLog::UdpLogger udpLogger;
    udpLogger.DoLogging();

    StartData startData = getStartData();

    fout.open("output.log", std::ios::app);

    if (fout.is_open()) {
        fout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    }

    wiringPiSetupGpio();
    setupSubscriptions();

    Picar car;
    car.init();

    setBSMHandler([] () {});
    setICAHandler([] () {});

    int count = 0;
    while (count < 4) {
        try {
            car.runToLine();
            car.moveForward();
            car.turnLeft();
            car.runToLine();
        } catch(...) {
            car.stop();
            exit(-1);
        }
        ++count;
    }

    car.stop();

    fout.close();
    return 0;
}


StartData getStartData()
{
    StartData out{};
    std::cin >> out.lane;
    std::cin >> out.targetIntersection;
    return out;
}
