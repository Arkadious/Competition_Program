#include "vex.hpp"

using namespace vex;

int32_t axis4 = 0;
int32_t axis3 = 0;
int32_t axis1 = 0;
int32_t axis2 = 0;

double joystick_magnitude_left = 0.0;
double joystick_magnitude_right = 0.0;
double joystick_angle_left = 0.0;
double joystick_angle_right = 0.0;

int joystick_tracking(void) {
  // Implement a deadzone for the joysticks to prevent drift.
  while(Competition.isDriverControl() && Competition.isEnabled()) {
    // Calculate the magnitude and angle of the left and right joysticks.
    joystick_magnitude_left = sqrt(pow(axis3, 2) + pow(axis4, 2));
    joystick_magnitude_right = sqrt(pow(axis2, 2) + pow(axis1, 2));
    joystick_angle_left = atan2(axis3, axis4) * 180.0 / M_PI;
    joystick_angle_right = atan2(axis2, axis1) * 180.0 / M_PI;

    if(joystick_angle_left < 0) {
      joystick_angle_left += 360.0;
    }
    if(joystick_angle_right < 0) {
      joystick_angle_right += 360.0;
    }

    this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                                // prevent wasted resources.
  }

  return 0;
}