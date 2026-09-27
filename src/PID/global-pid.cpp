#include "vex.hpp"

using namespace vex;

bool PID_enabled = true;

double LeftFrontDrive_PID_values[3];
double LeftBackDrive_PID_values[3];
double RightFrontDrive_PID_values[3];
double RightBackDrive_PID_values[3];
double MiddleStrafeDrive_PID_values[3];

PID LeftFrontDrive_PID = PID(100.0, -100.0, 0.0, 0.0, 0.0);
PID LeftBackDrive_PID = PID(100.0, -100.0, 0.0, 0.0, 0.0);
PID RightFrontDrive_PID = PID(100.0, -100.0, 0.0, 0.0, 0.0);
PID RightBackDrive_PID = PID(100.0, -100.0, 0.0, 0.0, 0.0);
PID MiddleStrafeDrive_PID = PID(100.0, -100.0, 0.0, 0.0, 0.0);