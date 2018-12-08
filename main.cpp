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
#include "CarManager.h"
#include <fstream>
#include <memory>
#include "UdpLogger.h"

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

//    StartData startData = getStartData();

    fout.open("output.log", std::ios::app);

    if (fout.is_open()) {
        fout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    }

    wiringPiSetupGpio();

    std::shared_ptr<Picar> car(new Picar);
    car->init();

    CarManager carManager(car);

    int count = 0;
    while (count < 4) {
        try {
            car->runToLine();
            car->moveForward();
            car->turnLeft();
            car->runToLine();
        } catch(...) {
            car->stop();
            exit(-1);
        }
        ++count;
        std::cout << count << std::endl;
    }

    car->stop();

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
