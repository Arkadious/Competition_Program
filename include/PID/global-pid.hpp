#ifndef GLOBAL_PID_HPP
#define GLOBAL_PID_HPP

#include "PID/pid.hpp"

using namespace vex;

extern PID LeftFrontDrive_PID;
extern PID LeftBackDrive_PID;
extern PID RightFrontDrive_PID;
extern PID RightBackDrive_PID;
extern PID MiddleStrafeDrive_PID;

int PID_loop(void);

#endif