#include "vex.hpp"

using namespace vex;

bool Up = false;
bool Down = false;
bool Left = false;
bool Right = false;

bool X = false;
bool B = false;
bool A = false;
bool Y = false;

bool L1 = false;
bool L2 = false;
bool R1 = false;
bool R2 = false;

int button_tracking(void) {
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