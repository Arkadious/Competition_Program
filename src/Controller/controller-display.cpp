#include "vex.hpp"

using namespace vex;

int controller_display(void) {
  // Continuously update the controller screen with relevant information.
  while(Competition.isDriverControl() && Competition.isEnabled()) {
    Controller1.Screen.clearScreen();

    // Display the current battery voltage on the controller screen.
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Battery: %.2f V", static_cast<double>(Brain.Battery.voltage()));

    // Display the current time elapsed since the start of the match on the controller screen.
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Time: %.2f s", static_cast<double>(Brain.Timer.time(sec)));


    // Display the magnitude and angle of both joysticks on the V5 controller screen.
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("Left:  %.2f %.2f", static_cast<double>(joystick_magnitude_left), static_cast<double>(joystick_angle_left));
    Controller1.Screen.setCursor(4, 1);
    Controller1.Screen.print("Right: %.2f %.2f", static_cast<double>(joystick_magnitude_right), static_cast<double>(joystick_angle_right));

    Controller1.Screen.setCursor(5, 1);

    this_thread::sleep_for(100); // Sleep the thread for a short amount of time to
                                 // prevent wasted resources.
  }

  return 0;
}