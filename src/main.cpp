/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Brandon Montagnani                                        */
/*    Created:      26/3/2026, 6:50:20 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#define _USE_MATH_DEFINES

#include "vex.hpp"

using namespace vex;

void pre_auton(void);
void autonomous(void);
void usercontrol(void);

int main(void) {
  Brain.Timer.clear();

  competition::bStopAllTasksBetweenModes = false;

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  vexcodeInit();

  pre_auton();

  while(true) {
    wait(100, msec);
  }

  return 0;
}

void pre_auton(void) {
  thread brain_display_thread = thread(brain_display);;
  thread motor_tracking_thread = thread(motor_tracking);

  LeftFrontDrive.setMaxTorque(100, percent);
  LeftBackDrive.setMaxTorque(100, percent);
  RightFrontDrive.setMaxTorque(100, percent);
  RightBackDrive.setMaxTorque(100, percent);
  MiddleStrafeDrive.setMaxTorque(100, percent);

  LeftFrontDrive.setVelocity(100, percent);
  LeftBackDrive.setVelocity(100, percent);
  RightFrontDrive.setVelocity(100, percent);
  RightBackDrive.setVelocity(100, percent);
  MiddleStrafeDrive.setVelocity(100, percent);

  LeftFrontDrive.setStopping(hold);
  LeftBackDrive.setStopping(hold);
  RightFrontDrive.setStopping(hold);
  RightBackDrive.setStopping(hold);
  MiddleStrafeDrive.setStopping(hold);

  LeftFrontDrive.spinToPosition(0, degrees, true);
  LeftBackDrive.spinToPosition(0, degrees, true);
  RightFrontDrive.spinToPosition(0, degrees, true);
  RightBackDrive.spinToPosition(0, degrees, true);
  MiddleStrafeDrive.spinToPosition(0, degrees, true);

  LeftFrontDrive.setPosition(0, degrees);
  LeftBackDrive.setPosition(0, degrees);
  RightFrontDrive.setPosition(0, degrees);
  RightBackDrive.setPosition(0, degrees);
  MiddleStrafeDrive.setPosition(0, degrees);

  while(Competition.isEnabled()) {
    wait(20, msec);
  }

  brain_display_thread.interrupt();
  motor_tracking_thread.interrupt();
}

void autonomous(void) {
  LeftFrontDrive.setMaxTorque(100, percent);
  LeftBackDrive.setMaxTorque(100, percent);
  RightFrontDrive.setMaxTorque(100, percent);
  RightBackDrive.setMaxTorque(100, percent);
  MiddleStrafeDrive.setMaxTorque(100, percent);

  LeftFrontDrive.setVelocity(50, percent);
  LeftBackDrive.setVelocity(50, percent);
  RightFrontDrive.setVelocity(50, percent);
  RightBackDrive.setVelocity(50, percent);
  MiddleStrafeDrive.setVelocity(50, percent);

  LeftFrontDrive.setStopping(hold);
  LeftBackDrive.setStopping(hold);
  RightFrontDrive.setStopping(hold);
  RightBackDrive.setStopping(hold);
  MiddleStrafeDrive.setStopping(hold);

  Brain.Timer.clear();

  thread autonomous_background_tasks_thread = thread(autonomous_background_tasks);

  if(red_alliance == true) {

  }
  else {

  }

  autonomous_background_tasks_thread.interrupt();
}

int autonomous_background_tasks(void) {
  // Having a function run on a thread during the autonomous period.
  while(Competition.isAutonomous() && Competition.isEnabled()) {

    this_thread::sleep_for(20);
  }

  LeftFrontDrive.stop();
  LeftBackDrive.stop();
  RightFrontDrive.stop();
  RightBackDrive.stop();
  MiddleStrafeDrive.stop();

  return 0;
}

void usercontrol(void) {
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

  Brain.Timer.clear();

  thread usercontrol_joysticks_thread = thread(usercontrol_joysticks);
  thread usercontrol_buttons_thread = thread(usercontrol_buttons);
  thread joystick_tracking_thread = thread(joystick_tracking);
  thread PID_loop_thread = thread(PID_loop);

  while(Competition.isDriverControl() && Competition.isEnabled()) {
    axis3 = Controller1.Axis3.position();
    axis4 = Controller1.Axis4.position();
    axis1 = Controller1.Axis1.position();
    axis2 = Controller1.Axis2.position();

    Up = Controller1.ButtonUp.pressing();
    Down = Controller1.ButtonDown.pressing();
    Left = Controller1.ButtonLeft.pressing();
    Right = Controller1.ButtonRight.pressing();

    X = Controller1.ButtonX.pressing();
    B = Controller1.ButtonB.pressing();
    A = Controller1.ButtonA.pressing();
    Y = Controller1.ButtonY.pressing();

    L1 = Controller1.ButtonL1.pressing();
    L2 = Controller1.ButtonL2.pressing();
    R1 = Controller1.ButtonR1.pressing();
    R2 = Controller1.ButtonR2.pressing();

    wait(10, msec);
  }

  usercontrol_joysticks_thread.interrupt();
  usercontrol_buttons_thread.interrupt();
  joystick_tracking_thread.interrupt();
  PID_loop_thread.interrupt();
}

/*----------------------------------------------------------------------------*/
/* User generated functions                                                   */
/*----------------------------------------------------------------------------*/

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

int motor_tracking(void) {
  // Continuously track information from the motors for debugging purposes.
  while(Competition.isEnabled()) {
    // Track motor voltage, current, power, temperature, and efficiency.
    LeftFrontDrive_voltage_output = LeftFrontDrive.voltage(volt);
    LeftBackDrive_voltage_output = LeftBackDrive.voltage(volt);
    RightFrontDrive_voltage_output = RightFrontDrive.voltage(volt);
    RightBackDrive_voltage_output = RightBackDrive.voltage(volt);
    MiddleStrafeDrive_voltage_output = MiddleStrafeDrive.voltage(volt);

    LeftFrontDrive_current_output = LeftFrontDrive.current(amp);
    LeftBackDrive_current_output = LeftBackDrive.current(amp);
    RightFrontDrive_current_output = RightFrontDrive.current(amp);
    RightBackDrive_current_output = RightBackDrive.current(amp);
    MiddleStrafeDrive_current_output = MiddleStrafeDrive.current(amp);

    LeftFrontDrive_power_output = LeftFrontDrive.power(watt);
    LeftBackDrive_power_output = LeftBackDrive.power(watt);
    RightFrontDrive_power_output = RightFrontDrive.power(watt);
    RightBackDrive_power_output = RightBackDrive.power(watt);
    MiddleStrafeDrive_power_output = MiddleStrafeDrive.power(watt);

    LeftFrontDrive_temperature_output = LeftFrontDrive.temperature(celsius);
    LeftBackDrive_temperature_output = LeftBackDrive.temperature(celsius);
    RightFrontDrive_temperature_output = RightFrontDrive.temperature(celsius);
    RightBackDrive_temperature_output = RightBackDrive.temperature(celsius);
    MiddleStrafeDrive_temperature_output = MiddleStrafeDrive.temperature(celsius);

    LeftFrontDrive_torque_output = LeftFrontDrive.torque(Nm);
    LeftBackDrive_torque_output = LeftBackDrive.torque(Nm);
    RightFrontDrive_torque_output = RightFrontDrive.torque(Nm);
    RightBackDrive_torque_output = RightBackDrive.torque(Nm);
    MiddleStrafeDrive_torque_output = MiddleStrafeDrive.torque(Nm);

    LeftFrontDrive_efficiency_output = LeftFrontDrive.efficiency(percent);
    LeftBackDrive_efficiency_output = LeftBackDrive.efficiency(percent);
    RightFrontDrive_efficiency_output = RightFrontDrive.efficiency(percent);
    RightBackDrive_efficiency_output = RightBackDrive.efficiency(percent);
    MiddleStrafeDrive_efficiency_output = MiddleStrafeDrive.efficiency(percent);

    // Track the position and velocity of the driver motors.
    LeftFrontDrive_position_output = LeftFrontDrive.position(degrees);
    LeftBackDrive_position_output = LeftBackDrive.position(degrees);
    RightFrontDrive_position_output = RightFrontDrive.position(degrees);
    RightBackDrive_position_output = RightBackDrive.position(degrees);
    MiddleStrafeDrive_position_output = MiddleStrafeDrive.position(degrees);

    LeftFrontDrive_percent_output = LeftFrontDrive.velocity(percent);
    LeftBackDrive_percent_output = LeftBackDrive.velocity(percent);
    RightFrontDrive_percent_output = RightFrontDrive.velocity(percent);
    RightBackDrive_percent_output = RightBackDrive.velocity(percent);
    MiddleStrafeDrive_percent_output = MiddleStrafeDrive.velocity(percent);

    LeftFrontDrive_rpm_output = LeftFrontDrive.velocity(rpm);
    LeftBackDrive_rpm_output = LeftBackDrive.velocity(rpm);
    RightFrontDrive_rpm_output = RightFrontDrive.velocity(rpm);
    RightBackDrive_rpm_output = RightBackDrive.velocity(rpm);
    MiddleStrafeDrive_rpm_output = MiddleStrafeDrive.velocity(rpm);

    // Convert rpm to radians per second
    LeftFrontDrive_angular_velocity_output = LeftFrontDrive.velocity(rpm) * 2 * M_PI / 60.0; 
    LeftBackDrive_angular_velocity_output = LeftBackDrive.velocity(rpm) * 2 * M_PI / 60.0;
    RightFrontDrive_angular_velocity_output = RightFrontDrive.velocity(rpm) * 2 * M_PI / 60.0;
    RightBackDrive_angular_velocity_output = RightBackDrive.velocity(rpm) * 2 * M_PI / 60.0;
    MiddleStrafeDrive_angular_velocity_output = MiddleStrafeDrive.velocity(rpm) * 2 * M_PI / 60.0;

    // Convert rpm to linear velocity in millimeters per second.
    LeftFrontDrive_linear_velocity_output = LeftFrontDrive_angular_velocity_output * wheel_radius * 1000.0;
    LeftBackDrive_linear_velocity_output = LeftBackDrive_angular_velocity_output * wheel_radius * 1000.0;
    RightFrontDrive_linear_velocity_output = RightFrontDrive_angular_velocity_output * wheel_radius * 1000.0;
    RightBackDrive_linear_velocity_output = RightBackDrive_angular_velocity_output * wheel_radius * 1000.0;
    MiddleStrafeDrive_linear_velocity_output = MiddleStrafeDrive_angular_velocity_output * wheel_radius * 1000.0;

    // Track if the drive motors are spinning and in which direction.
    LeftFrontDrive_isDone_output = LeftFrontDrive.isDone();
    LeftBackDrive_isDone_output = LeftBackDrive.isDone();
    RightFrontDrive_isDone_output = RightFrontDrive.isDone();
    RightBackDrive_isDone_output = RightBackDrive.isDone();
    MiddleStrafeDrive_isDone_output = MiddleStrafeDrive.isDone();

    LeftFrontDrive_isSpinning_output = LeftFrontDrive.isSpinning();
    LeftBackDrive_isSpinning_output = LeftBackDrive.isSpinning();
    RightFrontDrive_isSpinning_output = RightFrontDrive.isSpinning();
    RightBackDrive_isSpinning_output = RightBackDrive.isSpinning();
    MiddleStrafeDrive_isSpinning_output = MiddleStrafeDrive.isSpinning();

    LeftFrontDrive_direction_output = LeftFrontDrive.direction();
    LeftBackDrive_direction_output = LeftBackDrive.direction();
    RightFrontDrive_direction_output = RightFrontDrive.direction();
    RightBackDrive_direction_output = RightBackDrive.direction();
    MiddleStrafeDrive_direction_output = MiddleStrafeDrive.direction();

    this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                                // prevent wasted resources.
  }

  return 0;
}

int usercontrol_joysticks(void) {
  // Continuously update the drive motors based on the controller joystick values.
  while(Competition.isDriverControl() && Competition.isEnabled()) {
    // Implement a deadzone for the joysticks to prevent drift.
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

    axis4_percent_input = axis4;
    axis3_percent_input = axis3;
    axis1_percent_input = axis1;
    axis2_percent_input = axis2;

    LeftFrontDrive_percent_input = axis3_percent_input + axis1_percent_input;
    LeftBackDrive_percent_input = axis3_percent_input + axis1_percent_input;
    RightFrontDrive_percent_input = axis3_percent_input + axis1_percent_input;
    RightBackDrive_percent_input = axis3_percent_input + axis1_percent_input;
    MiddleStrafeDrive_percent_input = axis4_percent_input;

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

int usercontrol_buttons(void) {
  // Continuously check the state of the buttons on the controller and perform actions based on them.
  Controller1.ButtonUp.pressed(onevent_Controller1_ButtonUp_pressed);
  Controller1.ButtonUp.released(onevent_Controller1_ButtonUp_released);
  Controller1.ButtonDown.pressed(onevent_Controller1_ButtonDown_pressed);
  Controller1.ButtonDown.released(onevent_Controller1_ButtonDown_released);
  Controller1.ButtonLeft.pressed(onevent_Controller1_ButtonLeft_pressed);
  Controller1.ButtonLeft.released(onevent_Controller1_ButtonLeft_released);
  Controller1.ButtonRight.pressed(onevent_Controller1_ButtonRight_pressed);
  Controller1.ButtonRight.released(onevent_Controller1_ButtonRight_released);

  Controller1.ButtonX.pressed(onevent_Controller1_ButtonX_pressed);
  Controller1.ButtonX.released(onevent_Controller1_ButtonX_released);
  Controller1.ButtonB.pressed(onevent_Controller1_ButtonB_pressed);
  Controller1.ButtonB.released(onevent_Controller1_ButtonB_released);
  Controller1.ButtonY.pressed(onevent_Controller1_ButtonY_pressed);
  Controller1.ButtonY.released(onevent_Controller1_ButtonY_released);
  Controller1.ButtonA.pressed(onevent_Controller1_ButtonA_pressed);
  Controller1.ButtonA.released(onevent_Controller1_ButtonA_released);

  Controller1.ButtonL1.pressed(onevent_Controller1_ButtonL1_pressed);
  Controller1.ButtonL1.released(onevent_Controller1_ButtonL1_released);
  Controller1.ButtonL2.pressed(onevent_Controller1_ButtonL2_pressed);
  Controller1.ButtonL2.released(onevent_Controller1_ButtonL2_released);
  Controller1.ButtonR1.pressed(onevent_Controller1_ButtonR1_pressed);
  Controller1.ButtonR1.released(onevent_Controller1_ButtonR1_released);
  Controller1.ButtonR2.pressed(onevent_Controller1_ButtonR2_pressed);
  Controller1.ButtonR2.released(onevent_Controller1_ButtonR2_released);

  while(Competition.isDriverControl() && Competition.isEnabled()) {

    this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                                // prevent wasted resources.
  }

  return 0;
}

void onevent_Controller1_ButtonUp_pressed(void) {
  // Code to execute when the up button on the controller is pressed.
  waitUntil(!Controller1.ButtonUp.pressing());
}

void onevent_Controller1_ButtonUp_released(void) {
  // Code to execute when the up button on the controller is released.

  this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                              // prevent wasted resources.
}

void onevent_Controller1_ButtonDown_pressed(void) {
  // Code to execute when the down button on the controller is pressed.
  waitUntil(!Controller1.ButtonDown.pressing());
}

void onevent_Controller1_ButtonDown_released(void) {
  // Code to execute when the down button on the controller is released.

  this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                              // prevent wasted resources.
}

void onevent_Controller1_ButtonLeft_pressed(void) {
  // Code to execute when the left button on the controller is pressed.
  waitUntil(!Controller1.ButtonLeft.pressing());
}

void onevent_Controller1_ButtonLeft_released(void) {
  // Code to execute when the left button on the controller is released.

  this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                              // prevent wasted resources.
}

void onevent_Controller1_ButtonRight_pressed(void) {
  // Code to execute when the right button on the controller is pressed.
  waitUntil(!Controller1.ButtonRight.pressing());
}

void onevent_Controller1_ButtonRight_released(void) {
  // Code to execute when the right button on the controller is released.

  this_thread::sleep_for(10); // Sleep the thread for a short amount of time to
                              // prevent wasted resources.
}

void onevent_Controller1_ButtonX_pressed(void) {
  // Code to execute when the X button on the controller is pressed.
  waitUntil(!Controller1.ButtonX.pressing());
}

void onevent_Controller1_ButtonX_released(void) {
  // Code to execute when the X button on the controller is released.
}

void onevent_Controller1_ButtonB_pressed(void) {
  // Code to execute when the B button on the controller is pressed.
  waitUntil(!Controller1.ButtonB.pressing());
}

void onevent_Controller1_ButtonB_released(void) {
  // Code to execute when the B button on the controller is released.
}

void onevent_Controller1_ButtonY_pressed(void) {
  // Code to execute when the Y button on the controller is pressed.
  waitUntil(!Controller1.ButtonY.pressing());
}

void onevent_Controller1_ButtonY_released(void) {
  // Code to execute when the Y button on the controller is released.
}

void onevent_Controller1_ButtonA_pressed(void) {
  // Code to execute when the A button on the controller is pressed.
  waitUntil(!Controller1.ButtonA.pressing());
}

void onevent_Controller1_ButtonA_released(void) {
  // Code to execute when the A button on the controller is released.
}

void onevent_Controller1_ButtonL1_pressed(void) {
  // Code to execute when the L1 button on the controller is pressed.
  while(Controller1.ButtonL1.pressing()) {
    this_thread::sleep_for(10);
  }
}

void onevent_Controller1_ButtonL1_released(void) {
  // Code to execute when the L1 button on the controller is released.
}

void onevent_Controller1_ButtonL2_pressed(void) {
  // Code to execute when the L2 button on the controller is pressed.
  while(Controller1.ButtonL2.pressing()) {
    this_thread::sleep_for(10);
  }
}

void onevent_Controller1_ButtonL2_released(void) {
  // Code to execute when the L2 button on the controller is released.
}

void onevent_Controller1_ButtonR1_pressed(void) {
  // Code to execute when the R1 button on the controller is pressed.
  while(Controller1.ButtonR1.pressing()) {
    this_thread::sleep_for(10);
  }
}

void onevent_Controller1_ButtonR1_released(void) {
  // Code to execute when the R1 button on the controller is released.
}

void onevent_Controller1_ButtonR2_pressed(void) {
  // Code to execute when the R2 button on the controller is pressed.
  while(Controller1.ButtonR2.pressing()) {
    this_thread::sleep_for(10);
  }
}

void onevent_Controller1_ButtonR2_released(void) {
  // Code to execute when the R2 button on the controller is released.
}


int joystick_tracking(void) {
  Controller1.Screen.clearScreen();

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

    // Display the magnitude and angle of both joysticks on the V5 controller screen.
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Left:  %.2f %.2f", static_cast<double>(joystick_magnitude_left), static_cast<double>(joystick_angle_left));

    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Right: %.2f %.2f", static_cast<double>(joystick_magnitude_right), static_cast<double>(joystick_angle_right));

    Controller1.Screen.setCursor(3, 1);

    this_thread::sleep_for(200); // Sleep the thread for a short amount of time to
                                // prevent wasted resources.

    Controller1.Screen.clearLine(1);
    Controller1.Screen.clearLine(2);
    Controller1.Screen.clearLine(3);
  }

  return 0;
}

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

/*
bool spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  LeftFrontDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  LeftBackDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  RightFrontDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  RightBackDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  MiddleStrafeDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);

  return true;
}

bool spinToPosition(double rotation, rotationUnits units, bool waitForCompletion = true) {
  LeftFrontDrive.spinToPosition(rotation, units, waitForCompletion);
  LeftBackDrive.spinToPosition(rotation, units, waitForCompletion);
  RightFrontDrive.spinToPosition(rotation, units, waitForCompletion);
  RightBackDrive.spinToPosition(rotation, units, waitForCompletion);
  MiddleStrafeDrive.spinToPosition(rotation, units, waitForCompletion);

  return true;
}


bool turnToHeading(double heading, rotationUnits units, bool waitForCompletion = true) {
  // Calculate the most efficient direction to turn based on the current 
  // heading and the target heading

  directionType turn_direction = forward;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;
  
  if(heading_error > 180) {
    heading_error -= 360;
  }
  else if(heading_error < -180) {
    heading_error += 360;
  }
  else {
    heading_error = heading_error;
  }

  if(heading_error > 0) {
    turn_direction = forward;
  }
  else if(heading_error < 0) {
    turn_direction = reverse;
  }
  else {
    turn_direction = forward; // default to forward if the error is zero
  }

  if(turn_direction == forward) {
    LeftFrontDrive.spin(reverse);
    LeftBackDrive.spin(reverse);
    RightFrontDrive.spin(forward);
    RightBackDrive.spin(forward);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    LeftFrontDrive.spin(forward);
    LeftBackDrive.spin(forward);
    RightFrontDrive.spin(reverse);
    RightBackDrive.spin(reverse);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }

  return true;
}

bool turnToHeading(directionType dir, double heading, rotationUnits units, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the turn direction determined by the 'dir' parameter 
  // instead of calculating it based on the heading error.

  // The implementation would involve spinning the motors in the 
  // specified direction until the target heading is reached, and 
  // then stopping the motors.

  directionType turn_direction = dir;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;

  if(dir == forward) {
    LeftFrontDrive.spin(reverse);
    LeftBackDrive.spin(reverse);
    RightFrontDrive.spin(forward);
    RightBackDrive.spin(forward);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(dir == reverse) {
    LeftFrontDrive.spin(forward);
    LeftBackDrive.spin(forward);
    RightFrontDrive.spin(reverse);
    RightBackDrive.spin(reverse);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}

bool turnToHeading(double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the motors spinning at the specified velocity instead 
  // of a default speed.

  // The implementation would involve spinning the motors at the 
  // specified velocity until the target heading is reached, and 
  // then stopping the motors.

  directionType turn_direction = forward;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;
  
  if(heading_error > 180) {
    heading_error -= 360;
  }
  else if(heading_error < -180) {
    heading_error += 360;
  }
  else {
    heading_error = heading_error;
  }

  if(heading_error > 0) {
    turn_direction = forward;
  }
  else if(heading_error < 0) {
    turn_direction = reverse;
  }
  else {
    turn_direction = forward; // default to forward if the error is zero
  }

  if(turn_direction == forward) {
    LeftFrontDrive.spin(reverse, velocity, units_v);
    LeftBackDrive.spin(reverse, velocity, units_v);
    RightFrontDrive.spin(forward, velocity, units_v);
    RightBackDrive.spin(forward, velocity, units_v);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(turn_direction == reverse) {
    LeftFrontDrive.spin(forward, velocity, units_v);
    LeftBackDrive.spin(forward, velocity, units_v);
    RightFrontDrive.spin(reverse, velocity, units_v);
    RightBackDrive.spin(reverse, velocity, units_v);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}

bool turnToHeading(directionType dir, double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the turn direction determined by the 'dir' parameter 
  // instead of calculating it based on the heading error, and with 
  // the motors spinning at the specified velocity instead of a default speed.

  // The implementation would involve spinning the motors in the 
  // specified direction at the specified velocity until the target 
  // heading is reached, and then stopping the motors.

  directionType turn_direction = dir;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;

  if(dir == forward) {
    LeftFrontDrive.spin(reverse, velocity, units_v);
    LeftBackDrive.spin(reverse, velocity, units_v);
    RightFrontDrive.spin(forward, velocity, units_v);
    RightBackDrive.spin(forward, velocity, units_v);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(dir == reverse) {
    LeftFrontDrive.spin(forward, velocity, units_v);
    LeftBackDrive.spin(forward, velocity, units_v);
    RightFrontDrive.spin(reverse, velocity, units_v);
    RightBackDrive.spin(reverse, velocity, units_v);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}
*/