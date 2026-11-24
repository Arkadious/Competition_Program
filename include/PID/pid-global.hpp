#ifndef PID_GLOBAL_HPP
#define PID_GLOBAL_HPP

#include "pid.hpp"

using namespace vex;

extern PID LeftFrontDrive_PID;
extern PID LeftBackDrive_PID;
extern PID RightFrontDrive_PID;
extern PID RightBackDrive_PID;
extern PID MiddleStrafeDrive_PID;

extern bool PID_enabled;

extern double LeftFrontDrive_PID_values[3];
extern double LeftBackDrive_PID_values[3];
extern double RightFrontDrive_PID_values[3];
extern double RightBackDrive_PID_values[3];
extern double MiddleStrafeDrive_PID_values[3];

extern int32_t value_select;

int PID_loop(void);

#endif // PID_GLOBAL_HPP