#ifndef ROBOT_CONFIG_HPP
#define ROBOT_CONFIG_HPP

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
extern brain Brain;

// A global instance of competition
extern competition Competition;

// VEXcode devices
extern motor LeftFrontDrive;
extern motor LeftBackDrive;
extern motor RightFrontDrive;
extern motor RightBackDrive;
extern motor MiddleStrafeDrive;
extern inertial Inertial6;
extern rotation Rotation7;
extern gps GPS8;
extern distance Distance9;
extern optical Optical10;
extern controller Controller1;
extern controller Controller2;
extern motor_group LeftDrive;
extern motor_group RightDrive;

extern bool RemoteControlCodeEnabled;

/*----------------------------------------------------------------------------*/
/* Used to initialize code/tasks/devices added using tools in VEXcode Pro.    */
/* This should be called at the start of your int main function.              */
/*----------------------------------------------------------------------------*/

void vexcodeInit(void);
void initializeRandomSeed(void);
void playVexcodeSound(const char *soundName);

#endif