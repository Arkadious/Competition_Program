#include "vex.hpp"

using namespace vex;

int PID_loop(void) {
  // Continuously run a PID control loop for the drive motors.
  timer PID_timer = timer();

  while(Competition.isDriverControl() && Competition.isEnabled()) {
    LeftFrontDrive_percent = LeftFrontDrive_PID.calculate(LeftFrontDrive_percent_input, LeftFrontDrive_percent_output, PID_timer.time(msec));
    LeftBackDrive_percent = LeftBackDrive_PID.calculate(LeftBackDrive_percent_input, LeftBackDrive_percent_output, PID_timer.time(msec));
    RightFrontDrive_percent = RightFrontDrive_PID.calculate(RightFrontDrive_percent_input, RightFrontDrive_percent_output, PID_timer.time(msec));
    RightBackDrive_percent = RightBackDrive_PID.calculate(RightBackDrive_percent_input, RightBackDrive_percent_output, PID_timer.time(msec));
    MiddleStrafeDrive_percent = MiddleStrafeDrive_PID.calculate(MiddleStrafeDrive_percent_input, MiddleStrafeDrive_percent_output, PID_timer.time(msec));

    LeftFrontDrive_PID_values[0] = LeftFrontDrive_PID.get_kP();
    LeftFrontDrive_PID_values[1] = LeftFrontDrive_PID.get_kI();
    LeftFrontDrive_PID_values[2] = LeftFrontDrive_PID.get_kD();

    LeftBackDrive_PID_values[0] = LeftBackDrive_PID.get_kP();
    LeftBackDrive_PID_values[1] = LeftBackDrive_PID.get_kI();
    LeftBackDrive_PID_values[2] = LeftBackDrive_PID.get_kD();

    RightFrontDrive_PID_values[0] = RightFrontDrive_PID.get_kP();
    RightFrontDrive_PID_values[1] = RightFrontDrive_PID.get_kI();
    RightFrontDrive_PID_values[2] = RightFrontDrive_PID.get_kD();

    RightBackDrive_PID_values[0] = RightBackDrive_PID.get_kP();
    RightBackDrive_PID_values[1] = RightBackDrive_PID.get_kI();
    RightBackDrive_PID_values[2] = RightBackDrive_PID.get_kD();

    MiddleStrafeDrive_PID_values[0] = MiddleStrafeDrive_PID.get_kP();
    MiddleStrafeDrive_PID_values[1] = MiddleStrafeDrive_PID.get_kI();
    MiddleStrafeDrive_PID_values[2] = MiddleStrafeDrive_PID.get_kD();

    this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                                // prevent wasted resources.
  }

  return 0;
}