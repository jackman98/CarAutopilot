#ifndef PICAR_H
#define PICAR_H

#include <atomic>
#include <stdio.h>
#include <vector>
#include <Python.h>

struct TurnParams
{
    int leftMotorSpeed;
    int rightMotorSpeed;
    int rotationTimeMS;
    int startDetectTimeMS;
    int maxStartSpeed;
};

struct calibrationValues
{
    calibrationValues(): accelerateTimeMS(100), leftTurn({45, 35, 40, 35, 28}), rightTurn({35, 45, 40, 35, 28})  {}
    TurnParams leftTurn;
    TurnParams rightTurn;
    int accelerateTimeMS;

};

class AlphaBot;
class Picar
{
public:
    Picar();
    ~Picar();
    enum eDirection {
        FORWARD = 102,
        BACKWARD = 98,
        RIGHT = 114,
        LEFT = 108,
        STOP = 115,
        EXIT = 101,
    };

    void init(calibrationValues _params = calibrationValues());
    void run();
    void runToLine();
    void stop();
    void crossroads(eDirection direction);
    void turnLeft();
    void turnRight();
    void moveForward();
    void moveBackward();

    bool detectStopLine(int position);
    int calibrateOnLine();
private:
    void checkOrExit(PyObject* obj);
private:
    std::vector<int> listTupleToVector_Int(PyObject* incoming);
    int readLine(unsigned char white_line);
    int maximum = 35;
    PyObject* instance = nullptr;
    AlphaBot *Ab;
    std::atomic_bool stopFlag;
    calibrationValues params;
};
#endif
