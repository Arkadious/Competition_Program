#ifndef PID_HPP
#define PID_HPP

using namespace vex;

class implement_PID {
    private:
        double setpoint;
        double previous_time;
        double dT;
        double max;
        double min;
        double kP;
        double kI;
        double kD;
        double P;
        double I;
        double D;
        double previous_error;
    public:
        implement_PID(double maximum, double minimum, double kProportional, double kIntegral, double kDerivative);
        double calculate(double setpoint, double process_variable, double PID_timer);
        double get_kP();
        double get_kI();
        double get_kD();
        double get_dT();
        void set_kP(double new_kP);
        void set_kI(double new_kI);
        void set_kD(double new_kD);
        ~implement_PID();
};

class PID {
    private:
        implement_PID *pid_controller;
    public:
        PID(double maximum, double minimum, double kProportional, double kIntegral, double kDerivative);
        double calculate(double setpoint, double process_variable, double PID_timer);
        double get_kP();
        double get_kI();
        double get_kD();
        double get_dT();
        void set_kP(double new_kP);
        void set_kI(double new_kI);
        void set_kD(double new_kD);
        PID (const PID&) = delete;
        PID& operator=(const PID&) = delete;
        ~PID();
};

#endif