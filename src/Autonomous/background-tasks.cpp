#include "vex.hpp"

int autonomous_background_tasks(void) {
  // Having a function run on a thread during the autonomous period.


  while(Competition.isAutonomous() && Competition.isEnabled()) {

    this_thread::sleep_for(20);
  }

  LeftFrontDrive.stop();
  LeftBackDrive.stop();
  RightFrontDrive.stop();
  RightBackDrive.stop();
  MiddleStrafeDrive.stop();

  return 0;
}