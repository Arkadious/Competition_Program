#define _USE_MATH_DEFINES

#include "vex.hpp"

using namespace vex;

double wheel_diameter = 0.1016; // 4 inches in meters
double wheel_radius = wheel_diameter / 2;
double wheel_circumference = wheel_diameter * M_PI;

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