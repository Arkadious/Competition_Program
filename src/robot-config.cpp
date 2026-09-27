#include "vex.hpp"

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

// VEXcode generated functions
/*----------------------------------------------------------------------------*/
/* Used to initialize code/tasks/devices added using tools in VEXcode Pro.    */
/* This should be called at the start of your int main function.              */
/*----------------------------------------------------------------------------*/

void vexcodeInit(void) {
    waitUntil(Brain.Screen.pressing());

    initializeRandomSeed();
    Brain.Timer.clear();
    Brain.Screen.print("Device initialization...");
    Brain.Screen.setCursor(2, 1);
    wait(1000, msec);

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(0, 0, 240, 240);
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(240, 0, 240, 240);
    Brain.Screen.setFillColor(transparent);
    waitUntil(Brain.Screen.pressing());

    if ((Brain.Screen.xPosition() >= 0 && Brain.Screen.xPosition() <= 239) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 239)) {
    red_alliance = true;
    blue_alliance = false;
    }
    else {
      red_alliance = false;
      blue_alliance = true;
    }
    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(transparent);
    wait(1000, msec);

    if (red_alliance) {
      Brain.Screen.print("Red Alliance selected...");
    }
    else {
      Brain.Screen.print("Blue Alliance selected...");
    }
    wait(1000, msec);
    
    // Calibrate the drivetrain Inertial before starting
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Calibrating Inertial for Drivetrain");
    Inertial6.calibrate();
    
    // Wait for the Inertial calibration process to finish
    while (Inertial6.isCalibrating()) {
        wait(25, msec);
    }
    wait(200, msec);

    // Calibrate the GPS sensor before starting
    GPS8.calibrate();
    while (GPS8.isCalibrating()) {
      task::sleep(50);
    }

    // Reset the screen now that the calibration is complete
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    wait(50, msec);
}

// Generating and setting random seed
void initializeRandomSeed(void) {
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);

  // Combine these values into a single integer
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;

  // Set the seed
  srand(seed);
}

// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}