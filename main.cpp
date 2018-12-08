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

int main(int argc, char const *argv[])
{
    wiringPiSetupGpio();
    Picar car;
    car.init();
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
