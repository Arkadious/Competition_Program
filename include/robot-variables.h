#ifndef ROBOT_VARIABLES_H
#define ROBOT_VARIABLES_H

#include "PID/pid.h"

using namespace vex;

// Global instances of user defined variables
extern bool red_alliance;
extern bool blue_alliance;

extern int32_t axis3;
extern int32_t axis4;
extern int32_t axis1;
extern int32_t axis2;

extern bool Up;
extern bool Down;
extern bool Left;
extern bool Right;
extern bool X;
extern bool B;
extern bool A;
extern bool Y;
extern bool L1;
extern bool L2;
extern bool R1;
extern bool R2;

extern double joystick_magnitude_left;
extern double joystick_magnitude_right;
extern double joystick_angle_left;
extern double joystick_angle_right;

extern int32_t axis4_percent_input;
extern int32_t axis3_percent_input;
extern int32_t axis1_percent_input;
extern int32_t axis2_percent_input;

extern double axis4_rpm_input;
extern double axis3_rpm_input;
extern double axis1_rpm_input;
extern double axis2_rpm_input;

extern double LeftFrontDrive_percent_input;
extern double LeftBackDrive_percent_input;
extern double RightFrontDrive_percent_input;
extern double RightBackDrive_percent_input;
extern double MiddleStrafeDrive_percent_input;

extern double LeftFrontDrive_rpm_input;
extern double LeftBackDrive_rpm_input;
extern double RightFrontDrive_rpm_input;
extern double RightBackDrive_rpm_input;
extern double MiddleStrafeDrive_rpm_input;

extern double LeftFrontDrive_voltage_output;
extern double LeftBackDrive_voltage_output;
extern double RightFrontDrive_voltage_output;
extern double RightBackDrive_voltage_output;
extern double MiddleStrafeDrive_voltage_output;

extern double LeftFrontDrive_current_output;
extern double LeftBackDrive_current_output;
extern double RightFrontDrive_current_output;
extern double RightBackDrive_current_output;
extern double MiddleStrafeDrive_current_output;

extern double LeftFrontDrive_power_output;
extern double LeftBackDrive_power_output;
extern double RightFrontDrive_power_output;
extern double RightBackDrive_power_output;
extern double MiddleStrafeDrive_power_output;

extern double LeftFrontDrive_temperature_output;
extern double LeftBackDrive_temperature_output;
extern double RightFrontDrive_temperature_output;
extern double RightBackDrive_temperature_output;
extern double MiddleStrafeDrive_temperature_output;

extern double LeftFrontDrive_torque_output;
extern double LeftBackDrive_torque_output;
extern double RightFrontDrive_torque_output;
extern double RightBackDrive_torque_output;
extern double MiddleStrafeDrive_torque_output;

extern double LeftFrontDrive_efficiency_output;
extern double LeftBackDrive_efficiency_output;
extern double RightFrontDrive_efficiency_output;
extern double RightBackDrive_efficiency_output;
extern double MiddleStrafeDrive_efficiency_output;

extern double LeftFrontDrive_position_output;
extern double LeftBackDrive_position_output;
extern double RightFrontDrive_position_output;
extern double RightBackDrive_position_output;
extern double MiddleStrafeDrive_position_output;

extern double LeftFrontDrive_percent_output;
extern double LeftBackDrive_percent_output;
extern double RightFrontDrive_percent_output;
extern double RightBackDrive_percent_output;
extern double MiddleStrafeDrive_percent_output;

extern double LeftFrontDrive_percent;
extern double LeftBackDrive_percent;
extern double RightFrontDrive_percent;
extern double RightBackDrive_percent;
extern double MiddleStrafeDrive_percent;

extern double LeftFrontDrive_rpm_output;
extern double LeftBackDrive_rpm_output;
extern double RightFrontDrive_rpm_output;
extern double RightBackDrive_rpm_output;
extern double MiddleStrafeDrive_rpm_output;

extern double LeftFrontDrive_angular_velocity_output;
extern double LeftBackDrive_angular_velocity_output;
extern double RightFrontDrive_angular_velocity_output;
extern double RightBackDrive_angular_velocity_output;
extern double MiddleStrafeDrive_angular_velocity_output;

extern double LeftFrontDrive_linear_velocity_output;
extern double LeftBackDrive_linear_velocity_output;
extern double RightFrontDrive_linear_velocity_output;
extern double RightBackDrive_linear_velocity_output;
extern double MiddleStrafeDrive_linear_velocity_output;

extern bool LeftFrontDrive_isDone_output;
extern bool LeftBackDrive_isDone_output;
extern bool RightFrontDrive_isDone_output;
extern bool RightBackDrive_isDone_output;
extern bool MiddleStrafeDrive_isDone_output;

extern bool LeftFrontDrive_isSpinning_output;
extern bool LeftBackDrive_isSpinning_output;
extern bool RightFrontDrive_isSpinning_output;
extern bool RightBackDrive_isSpinning_output;
extern bool MiddleStrafeDrive_isSpinning_output;

extern directionType LeftFrontDrive_direction_output;
extern directionType LeftBackDrive_direction_output;
extern directionType RightFrontDrive_direction_output;
extern directionType RightBackDrive_direction_output;
extern directionType MiddleStrafeDrive_direction_output;

extern int32_t drive_cartridge_rpm;
extern int32_t deadzone;

extern double wheel_diameter; // 4 inches in meters
extern double wheel_radius;
extern double wheel_circumference;

extern bool PID_enabled;

extern double LeftFrontDrive_PID_values[3];
extern double LeftBackDrive_PID_values[3];
extern double RightFrontDrive_PID_values[3];
extern double RightBackDrive_PID_values[3];
extern double MiddleStrafeDrive_PID_values[3];

extern int32_t value_select;

extern PID LeftFrontDrive_PID;
extern PID LeftBackDrive_PID;
extern PID RightFrontDrive_PID;
extern PID RightBackDrive_PID;
extern PID MiddleStrafeDrive_PID;

/*----------------------------------------------------------------------------*/
/* Used to initialize code/tasks/devices added using tools in VEXcode Pro.    */
/* This should be called at the start of your int main function.              */
/*----------------------------------------------------------------------------*/

void vexcodeInit(void);
void initializeRandomSeed(void);
void playVexcodeSound(const char *soundName);

/*----------------------------------------------------------------------------*/
/* Used to initialize code/tasks/devices added using tools in VEXcode Pro.    */
/* This should be called at the start of your int main function.              */
/*----------------------------------------------------------------------------*/

int brain_display(void);
int motor_tracking(void);
int autonomous_background_tasks(void);
int usercontrol_joysticks(void);
int usercontrol_buttons(void);
int joystick_tracking(void);
int PID_loop(void);

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

#endif