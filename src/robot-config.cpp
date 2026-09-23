#include "vex.h"

using namespace vex;

using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// A global instance of competition
competition Competition;

// VEXcode device constructors
motor LeftFrontDrive = motor(PORT1, ratio18_1, false);
motor LeftBackDrive = motor(PORT2, ratio18_1, false);
motor RightFrontDrive = motor(PORT3, ratio18_1, true);
motor RightBackDrive = motor(PORT4, ratio18_1, true);
motor MiddleStrafeDrive = motor(PORT5, ratio18_1, false);
inertial Inertial6 = inertial(PORT6);
rotation Rotation7 = rotation(PORT7);
gps GPS8 = gps(PORT8, 0, 0, distanceUnits::mm, 0);
distance Distance9 = distance(PORT9);
optical Optical10 = optical(PORT10);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// Define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;