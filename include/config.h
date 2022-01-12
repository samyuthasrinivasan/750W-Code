#define CONFIG_H
#include "main.h"

const int FRONT_LEFT_MOTOR = 4;
const int FRONT_RIGHT_MOTOR = 7;
const int BACK_LEFT_MOTOR = 13;
const int BACK_RIGHT_MOTOR = 20;
const int FRONT_INTAKE_MOTOR = 5;
const int LEFT_LIFT_MOTOR = 10;
const int RIGHT_LIFT_MOTOR = 6;
const int BACK_INTAKE_MOTOR = 15;

extern okapi::Motor drive_fL;
extern okapi::Motor drive_fR;
extern okapi::Motor drive_bL;
extern okapi::Motor drive_bR;
extern okapi::Motor front_intake;
extern okapi::Motor back_intake;
extern okapi::Motor liftL;
extern okapi::Motor liftR;
extern std::shared_ptr<okapi::ChassisController> chassis;
extern int i;

extern okapi::Controller joystick;
extern okapi::ControllerButton backTakeIn;
extern okapi::ControllerButton backTakeOut;
extern okapi::ControllerButton frontTakeIn;
extern okapi::ControllerButton frontTakeOut;
extern okapi::ControllerButton up;
extern okapi::ControllerButton down;
extern okapi::ControllerButton left;
extern okapi::ControllerButton right;
extern okapi::ControllerButton x;
extern okapi::ControllerButton a;
extern okapi::ControllerButton y;
extern okapi::ControllerButton b;

extern okapi::MotorGroup lift;
extern okapi::MotorGroup front_drive;

extern okapi::ADIButton back_bumperswitch;

extern std::vector<double> acceleration;
extern bool auton_state;
extern int ind;
extern int totalTime;
extern okapi::IMU imu_x;
extern okapi::IMU imu_z;

extern okapi::ADIUltrasonic ultra_back;
extern okapi::ADIUltrasonic ultra_front;

extern pros::Task acceleration_tracker_task;

double getCurrentPosition();
void auton_selector();
void mbl_goal();
void left_win_point();
void right_win_point();
void new_auton_trial();
void move_dist(double spdL, double  spdR);
void front_clamp();
void back_clamp();
void front_unclamp();
void back_unclamp();
void lift_up();
void lift_down();
void turn_ccw(float spd, int time);
void turn_cw(float spd, int time);
void turn_ccw_PID(int deg);
void turn_cw_PID(int deg);
void stop();
void drive_PID(double dist);
void lift_PID(int deg);
void drive_tarePos();
void turn_PID(int deg);
void acceleration_tracker(void*);
