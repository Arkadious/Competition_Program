#include "vex.hpp"

using namespace vex;

int32_t deadzone = 5;
int32_t drive_cartridge_rpm = 200;

int32_t axis4_percent_input = 0;
int32_t axis3_percent_input = 0;
int32_t axis1_percent_input = 0;
int32_t axis2_percent_input = 0;

double axis4_rpm_input = 0.0;
double axis3_rpm_input = 0.0;
double axis1_rpm_input = 0.0;
double axis2_rpm_input = 0.0;

int usercontrol_drivetrain(void) {
  LeftFrontDrive.setMaxTorque(100, percent);
  LeftBackDrive.setMaxTorque(100, percent);
  RightFrontDrive.setMaxTorque(100, percent);
  RightBackDrive.setMaxTorque(100, percent);
  MiddleStrafeDrive.setMaxTorque(100, percent);

  LeftFrontDrive.setBrake(brake);
  LeftBackDrive.setBrake(brake);
  RightFrontDrive.setBrake(brake);
  RightBackDrive.setBrake(brake);
  MiddleStrafeDrive.setBrake(brake);

  // Continuously update the drive motors based on the controller joystick values.
  while(Competition.isDriverControl() && Competition.isEnabled()) {
    if(abs(axis4) <= deadzone) {
      axis4 = 0; // x axis of left joystick
    }
    if(abs(axis3) <= deadzone) {
      axis3 = 0; // y axis of left joystick
    }
    if(abs(axis1) <= deadzone) {
      axis1 = 0; // x axis of right joystick
    }
    if(abs(axis2) <= deadzone) {
      axis2 = 0; // y axis of right joystick
    }

    LeftFrontDrive_percent_input = axis3 + axis1;
    LeftBackDrive_percent_input = axis3 + axis1;
    RightFrontDrive_percent_input = axis3 + axis1;
    RightBackDrive_percent_input = axis3 + axis1;
    MiddleStrafeDrive_percent_input = axis4;

    LeftFrontDrive_rpm_input = LeftFrontDrive_percent_input * drive_cartridge_rpm / 100;
    LeftBackDrive_rpm_input = LeftBackDrive_percent_input * drive_cartridge_rpm / 100;
    RightFrontDrive_rpm_input = RightFrontDrive_percent_input * drive_cartridge_rpm / 100;
    RightBackDrive_rpm_input = RightBackDrive_percent_input * drive_cartridge_rpm / 100;
    MiddleStrafeDrive_rpm_input = MiddleStrafeDrive_percent_input * drive_cartridge_rpm / 100;

    if(LeftFrontDrive_percent_input != 0) {
      LeftFrontDrive.setVelocity(LeftFrontDrive_percent, percent);
      LeftFrontDrive.spin(forward);
    }
    else {
      LeftFrontDrive.stop();
    }

    if(LeftBackDrive_percent_input != 0) {
      LeftBackDrive.setVelocity(LeftBackDrive_percent, percent);
      LeftBackDrive.spin(forward);
    }
    else {
      LeftBackDrive.stop();
    }

    if(RightFrontDrive_percent_input != 0) {
      RightFrontDrive.setVelocity(RightFrontDrive_percent, percent);
      RightFrontDrive.spin(forward);
    }
    else {
      RightFrontDrive.stop();
    }

    if(RightBackDrive_percent_input != 0) {
      RightBackDrive.setVelocity(RightBackDrive_percent, percent);
      RightBackDrive.spin(forward);
    }
    else {
      RightBackDrive.stop();
    }

    if(MiddleStrafeDrive_percent_input != 0) {
      MiddleStrafeDrive.setVelocity(MiddleStrafeDrive_percent, percent);
      MiddleStrafeDrive.spin(forward);
    }
    else {
      MiddleStrafeDrive.stop();
    }

    this_thread::sleep_for(10);
  }

  LeftFrontDrive.stop();
  LeftBackDrive.stop();
  RightFrontDrive.stop();
  RightBackDrive.stop();
  MiddleStrafeDrive.stop();
  
  return 0;
}