#include "vex.h"

using namespace vex;

implement_PID::implement_PID(double maximum, double minimum, double kProportional, double kIntegral, double kDerivative) {
    previous_time = 0;
    dT = 0;
    max = maximum;
    min = minimum;
    kP = kProportional;
    kI = kIntegral;
    kD = kDerivative;
    P = 0;
    I = 0;
    D = 0;
    previous_error = 0;
}

double implement_PID::calculate(double setpoint, double process_variable, double PID_timer)
{
    double error;
    double PID_output;

    if (kP == 0 && kI == 0 && kD == 0) {
        PID_output = setpoint;
    }
    else {
        error = setpoint - process_variable;
        P = error;

        dT = PID_timer - previous_time;
        previous_time = PID_timer;

        if (error >= min && error <= max) {
            if (error == 0) {
                I = 0;
            }
            
        }
        else {
            if (error > max) {
                error = max;
                P = max;
            }
            if (error < min) {
                error = min;
                P = min;
            }
        }

        I += (error * dT);

        D = (error - previous_error) / dT;
        previous_error = error;

        PID_output = (P*kP) + (I*kI) + (D*kD);

        if (PID_output > max) {
            PID_output = max;
        }
        if (PID_output < min) {
            PID_output = min;
        }
    }
    
    return PID_output;
}

double implement_PID::get_kP() {
    return kP;
}

double implement_PID::get_kI() {
    return kI;
}

double implement_PID::get_kD() {
    return kD;
}

double implement_PID::get_dT() {
    return dT;
}

void implement_PID::set_kP(double new_kP) {
    kP = new_kP;
}

void implement_PID::set_kI(double new_kI) {
    kI = new_kI;
}

void implement_PID::set_kD(double new_kD) {
    kD = new_kD;
}

implement_PID::~implement_PID() {
    // Destructor code if needed
}

PID::PID(double maximum, double minimum, double kProportional, double kIntegral, double kDerivative) {
    pid_controller = new implement_PID(maximum, minimum, kProportional, kIntegral, kDerivative);
}

double PID::calculate(double setpoint, double process_variable, double PID_timer) {
    return pid_controller->calculate(setpoint, process_variable, PID_timer);
}

double PID::get_kP() {
    return pid_controller->get_kP();
}

double PID::get_kI() {
    return pid_controller->get_kI();
}

double PID::get_kD() {
    return pid_controller->get_kD();
}

double PID::get_dT() {
    return pid_controller->get_dT();
}

void PID::set_kP(double new_kP) {
    pid_controller->set_kP(new_kP);
}

void PID::set_kI(double new_kI) {
    pid_controller->set_kI(new_kI);
}

void PID::set_kD(double new_kD) {
    pid_controller->set_kD(new_kD);
}

PID::~PID() {
    delete pid_controller;
}