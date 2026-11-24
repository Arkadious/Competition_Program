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
  Brain.Timer.clear();

  thread motor_tracking_thread = thread(motor_tracking);
  thread brain_display_thread = thread(brain_display);
  
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
  Brain.Timer.clear();

  thread motor_tracking_thread = thread(motor_tracking);
  thread brain_display_thread = thread(brain_display);
  thread autonomous_background_tasks_thread = thread(autonomous_background_tasks);

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

  if(red_alliance == true) {

  }
  else {

  }

  motor_tracking_thread.interrupt();
  brain_display_thread.interrupt();
  autonomous_background_tasks_thread.interrupt();
}

void usercontrol(void) {
  Brain.Timer.clear();

  thread button_tracking_thread = thread(button_tracking);
  thread joystick_tracking_thread = thread(joystick_tracking);
  thread motor_tracking_thread = thread(motor_tracking);
  thread usercontrol_drivetrain_thread = thread(usercontrol_drivetrain);
  thread controller_display_thread = thread(controller_display);
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

  button_tracking_thread.interrupt();
  joystick_tracking_thread.interrupt();
  motor_tracking_thread.interrupt();
  usercontrol_drivetrain_thread.interrupt();
  PID_loop_thread.interrupt();
}