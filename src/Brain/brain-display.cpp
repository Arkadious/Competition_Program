#include "vex.hpp"

int brain_display(void) {
  // Continuously update the brain's display for debugging purposes.
  Brain.Screen.clearScreen();

  while(Competition.isEnabled()) {
    // Display the current state of the robot on the brain's screen for debugging purposes.
    for (int i = 1; i <=12; i++) {
      Brain.Screen.clearLine(i);
    }

    Brain.Screen.setCursor(1, 1);
    if(!Competition.isAutonomous() && !Competition.isDriverControl()) {
      Brain.Screen.print("Mode: Pre-Autonomous");
    }
    else if(Competition.isAutonomous()) {
      Brain.Screen.print("Mode: Autonomous");
    }
    else if(Competition.isDriverControl()) {
      Brain.Screen.print("Mode: Driver Control");
    }
    else {
      Brain.Screen.print("Mode: Undefined");
    }

    Brain.Screen.setCursor(2, 1);
    if(Brain.SDcard.isInserted()) {
      Brain.Screen.print("SD Card: Inserted");
    }
    else {
      Brain.Screen.print("SD Card: Not Inserted");
    }

    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("Mode Operation Time: %i seconds", static_cast<int>(Brain.Timer.time(sec)));

    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("Battery: %.2f%% %.2f Volts %.2f Amps", static_cast<float>(Brain.Battery.capacity(percent)), static_cast<float>(Brain.Battery.voltage(volt)), static_cast<float>(Brain.Battery.current(amp)));

    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("Drive Percent Output: %.2f%%, %.2f%%, %.2f%%, %.2f%%, %.2f%%", static_cast<float>(LeftFrontDrive_percent_output), static_cast<float>(LeftBackDrive_percent_output), static_cast<float>(RightFrontDrive_percent_output), static_cast<float>(RightBackDrive_percent_output), static_cast<float>(MiddleStrafeDrive_percent_output));

    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("Drive Angular Velocity: %.2f rad/s, %.2f rad/s, %.2f rad/s, %.2f rad/s, %.2f rad/s", static_cast<float>(LeftFrontDrive_rpm_output * 2 * M_PI / 60.0), static_cast<float>(LeftBackDrive_rpm_output * 2 * M_PI / 60.0), static_cast<float>(RightFrontDrive_rpm_output * 2 * M_PI / 60.0), static_cast<float>(RightBackDrive_rpm_output * 2 * M_PI / 60.0), static_cast<float>(MiddleStrafeDrive_rpm_output * 2 * M_PI / 60.0));

    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("Drive Linear Velocity: %.2f mm/s, %.2f mm/s, %.2f mm/s, %.2f mm/s, %.2f mm/s", static_cast<float>(LeftFrontDrive_linear_velocity_output), static_cast<float>(LeftBackDrive_linear_velocity_output), static_cast<float>(RightFrontDrive_linear_velocity_output), static_cast<float>(RightBackDrive_linear_velocity_output), static_cast<float>(MiddleStrafeDrive_linear_velocity_output));

    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("Inertial Heading: %.2f degrees", static_cast<float>(Inertial6.heading()));

    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("Inertial Acceleration: %.2f, %.2f, %.2f", static_cast<float>(Inertial6.acceleration(xaxis)), static_cast<float>(Inertial6.acceleration(yaxis)), static_cast<float>(Inertial6.acceleration(zaxis)));

    this_thread::sleep_for(500); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }

  return 0;
}