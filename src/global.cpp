#include "vex.hpp"

using namespace vex;

// User defined variables
bool red_alliance = true;
bool blue_alliance = false;

int32_t axis4 = 0;
int32_t axis3 = 0;
int32_t axis1 = 0;
int32_t axis2 = 0;

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

double joystick_magnitude_left = 0.0;
double joystick_magnitude_right = 0.0;
double joystick_angle_left = 0.0;
double joystick_angle_right = 0.0;

int32_t axis4_percent_input = 0;
int32_t axis3_percent_input = 0;
int32_t axis1_percent_input = 0;
int32_t axis2_percent_input = 0;

double axis4_rpm_input = 0.0;
double axis3_rpm_input = 0.0;
double axis1_rpm_input = 0.0;
double axis2_rpm_input = 0.0;

double LeftFrontDrive_percent_input = 0.0;
double LeftBackDrive_percent_input = 0.0;
double RightFrontDrive_percent_input = 0.0;
double RightBackDrive_percent_input = 0.0;
double MiddleStrafeDrive_percent_input = 0.0;

double LeftFrontDrive_rpm_input = 0.0;
double LeftBackDrive_rpm_input = 0.0;
double RightFrontDrive_rpm_input = 0.0;
double RightBackDrive_rpm_input = 0.0;
double MiddleStrafeDrive_rpm_input = 0.0;

double LeftFrontDrive_voltage_output = 0.0;
double LeftBackDrive_voltage_output = 0.0;
double RightFrontDrive_voltage_output = 0.0;
double RightBackDrive_voltage_output = 0.0;
double MiddleStrafeDrive_voltage_output = 0.0;

double LeftFrontDrive_current_output = 0.0;
double LeftBackDrive_current_output = 0.0;
double RightFrontDrive_current_output = 0.0;
double RightBackDrive_current_output = 0.0;
double MiddleStrafeDrive_current_output = 0.0;

double LeftFrontDrive_power_output = 0.0;
double LeftBackDrive_power_output = 0.0;
double RightFrontDrive_power_output = 0.0;
double RightBackDrive_power_output = 0.0;
double MiddleStrafeDrive_power_output = 0.0;

double LeftFrontDrive_temperature_output = 0.0;
double LeftBackDrive_temperature_output = 0.0;
double RightFrontDrive_temperature_output = 0.0;
double RightBackDrive_temperature_output = 0.0;
double MiddleStrafeDrive_temperature_output = 0.0;

double LeftFrontDrive_torque_output = 0.0;
double LeftBackDrive_torque_output = 0.0;
double RightFrontDrive_torque_output = 0.0;
double RightBackDrive_torque_output = 0.0;
double MiddleStrafeDrive_torque_output = 0.0;

double LeftFrontDrive_efficiency_output = 0.0;
double LeftBackDrive_efficiency_output = 0.0;
double RightFrontDrive_efficiency_output = 0.0;
double RightBackDrive_efficiency_output = 0.0;
double MiddleStrafeDrive_efficiency_output = 0.0;

double LeftFrontDrive_position_output = 0.0;
double LeftBackDrive_position_output = 0.0;
double RightFrontDrive_position_output = 0.0;
double RightBackDrive_position_output = 0.0;
double MiddleStrafeDrive_position_output = 0.0;

double LeftFrontDrive_percent_output = 0.0;
double LeftBackDrive_percent_output = 0.0;
double RightFrontDrive_percent_output = 0.0;
double RightBackDrive_percent_output = 0.0;
double MiddleStrafeDrive_percent_output = 0.0;

double LeftFrontDrive_percent = 0.0;
double LeftBackDrive_percent = 0.0;
double RightFrontDrive_percent = 0.0;
double RightBackDrive_percent = 0.0;
double MiddleStrafeDrive_percent = 0.0;

double LeftFrontDrive_rpm_output = 0.0;
double LeftBackDrive_rpm_output = 0.0;
double RightFrontDrive_rpm_output = 0.0;
double RightBackDrive_rpm_output = 0.0;
double MiddleStrafeDrive_rpm_output = 0.0;

double LeftFrontDrive_angular_velocity_output = 0.0;
double LeftBackDrive_angular_velocity_output = 0.0;
double RightFrontDrive_angular_velocity_output = 0.0;
double RightBackDrive_angular_velocity_output = 0.0;
double MiddleStrafeDrive_angular_velocity_output = 0.0;

double LeftFrontDrive_linear_velocity_output = 0.0;
double LeftBackDrive_linear_velocity_output = 0.0;
double RightFrontDrive_linear_velocity_output = 0.0;
double RightBackDrive_linear_velocity_output = 0.0;
double MiddleStrafeDrive_linear_velocity_output = 0.0;

bool LeftFrontDrive_isDone_output = true;
bool LeftBackDrive_isDone_output = true;
bool RightFrontDrive_isDone_output = true;
bool RightBackDrive_isDone_output = true;
bool MiddleStrafeDrive_isDone_output = true;

bool LeftFrontDrive_isSpinning_output = false;
bool LeftBackDrive_isSpinning_output = false;
bool RightFrontDrive_isSpinning_output = false;
bool RightBackDrive_isSpinning_output = false;
bool MiddleStrafeDrive_isSpinning_output = false;

directionType LeftFrontDrive_direction_output = forward;
directionType LeftBackDrive_direction_output = forward;
directionType RightFrontDrive_direction_output = forward;
directionType RightBackDrive_direction_output = forward;
directionType MiddleStrafeDrive_direction_output = forward;

int32_t drive_cartridge_rpm = 200;
int32_t deadzone = 5;

double wheel_diameter = 0.1016; // 4 inches in meters
double wheel_radius = wheel_diameter / 2;
double wheel_circumference = wheel_diameter * M_PI;

int32_t value_select = 0;