#ifndef GLOBAL_HPP
#define GLOBAL_HPP

using namespace vex;

// Global instances of user defined variables

/*----------------------------------------------------------------------------*/
/* Used to initialize code/tasks/devices added using tools in VEXcode Pro.    */
/* This should be called at the start of your int main function.              */
/*----------------------------------------------------------------------------*/

int button_tracking(void);
int joystick_tracking(void);
int motor_tracking(void);
int brain_display(void);
int controller_display(void);
int autonomous_background_tasks(void);
int usercontrol_drivetrain(void);

void onevent_Controller1_ButtonUp_pressed(void);
void onevent_Controller1_ButtonUp_released(void);
void onevent_Controller1_ButtonDown_pressed(void);
void onevent_Controller1_ButtonDown_released(void);
void onevent_Controller1_ButtonLeft_pressed(void);
void onevent_Controller1_ButtonLeft_released(void);
void onevent_Controller1_ButtonRight_pressed(void);
void onevent_Controller1_ButtonRight_released(void);

void onevent_Controller1_ButtonA_pressed(void);
void onevent_Controller1_ButtonA_released(void);
void onevent_Controller1_ButtonB_pressed(void);
void onevent_Controller1_ButtonB_released(void);
void onevent_Controller1_ButtonX_pressed(void);
void onevent_Controller1_ButtonX_released(void);
void onevent_Controller1_ButtonY_pressed(void);
void onevent_Controller1_ButtonY_released(void);

void onevent_Controller1_ButtonL1_pressed(void);
void onevent_Controller1_ButtonL1_released(void);
void onevent_Controller1_ButtonL2_pressed(void);
void onevent_Controller1_ButtonL2_released(void);
void onevent_Controller1_ButtonR1_pressed(void);
void onevent_Controller1_ButtonR1_released(void);
void onevent_Controller1_ButtonR2_pressed(void);
void onevent_Controller1_ButtonR2_released(void);

// bool spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
// bool spinToPosition(double rotation, rotationUnits units, bool waitForCompletion = true);

// bool turnToHeading(double heading, rotationUnits units, bool waitForCompletion = true);
// bool turnToHeading(directionType dir, double heading, rotationUnits units, bool waitForCompletion = true);
// bool turnToHeading(double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);
// bool turnToHeading(directionType dir, double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true);

#endif // GLOBAL_HPP