#include "config.h"
using namespace okapi;

void initialize() {
  front_intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  back_intake.setBrakeMode(AbstractMotor::brakeMode::hold);
  lift.setBrakeMode(AbstractMotor::brakeMode::hold);
  front_intake.tarePosition();
  back_intake.tarePosition();
  liftR.tarePosition();
  liftL.tarePosition();
  imu_x.reset();
  imu_z.reset();
  //Task tracker_task(acceleration_tracker,(void*)"not needed",TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT,"tracker task");
  //auton_selector();
  Task drive(drive_funct, (void*)"not needed", "driver control task");
}

void autonomous() {
  chassis -> setMaxVelocity (150);
  int count = 0;

  while ( !back_bumperswitch.isPressed()) {
    move_dist (150, 25);
    count += 25;
  }
  stop();

  for (int i = 0; i < 40; i++)
  back_clamp ();
  stop ();

  chassis->turnToAngle(90_deg);
  for (int i = 0; i < 40; i++)
  back_unclamp();
  stop();

  move_dist(180, 20);
  chassis->turnToAngle(-45_deg);
  move_dist(180, 40);
  stop();

  chassis->turnToAngle(-90_deg);
  while ( !back_bumperswitch.isPressed()) {
    move_dist (150, 25);
    count += 25;
  }
  stop();

  for (int i = 0; i < 40; i++)
  back_clamp ();
  stop ();

  for (int i = 0; i < 40; i++)
  back_unclamp ();
  stop ();

  //drive_PID(0.80);
  /*
  while(ultra.controllerGet() <
  move_dist(180, 25);
  */

  /*
  joystick.clear();
  delay(100);
  joystick.setText(0, 0, i + "");
  delay(100);
  switch(i){
    case 0: mbl_goal();
    break;
    case 1: left_win_point();
    break;
    case 2: right_win_point();
    break;
  }
  stop();
  */
}

void opcontrol() {
  auton_state = false;
  while(true){

    if ( frontTakeIn.isPressed() ) {

      front_clamp();

    } else if ( frontTakeOut.isPressed() ) {

      front_unclamp();

    } else {

      front_intake.moveVoltage(0);

    }

    if ( backTakeIn.isPressed() ) {

      back_clamp();

    } else if (backTakeOut.isPressed()) {

      back_unclamp();

    } else {

      back_intake.moveVoltage(0);

    }

    if ( up.isPressed() ) {

      lift_up();

    } else if ( down.isPressed() ) {

      lift_down());

    } else if ( left.isPressed() ) {

      lift_PID(900);
      printf("done - up 900");

    } else if ( right.isPressed() ) {

      lift_PID(-900);
      printf("done - down 900");

    } else {

      lift.moveVelocity(0);

    }

    delay(20);
  }
}
