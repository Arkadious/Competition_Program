/*
bool spinToPosition(double rotation, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  LeftFrontDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  LeftBackDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  RightFrontDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  RightBackDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);
  MiddleStrafeDrive.spinToPosition(rotation, units, velocity, units_v, waitForCompletion);

  return true;
}

bool spinToPosition(double rotation, rotationUnits units, bool waitForCompletion = true) {
  LeftFrontDrive.spinToPosition(rotation, units, waitForCompletion);
  LeftBackDrive.spinToPosition(rotation, units, waitForCompletion);
  RightFrontDrive.spinToPosition(rotation, units, waitForCompletion);
  RightBackDrive.spinToPosition(rotation, units, waitForCompletion);
  MiddleStrafeDrive.spinToPosition(rotation, units, waitForCompletion);

  return true;
}


bool turnToHeading(double heading, rotationUnits units, bool waitForCompletion = true) {
  // Calculate the most efficient direction to turn based on the current 
  // heading and the target heading

  directionType turn_direction = forward;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;
  
  if(heading_error > 180) {
    heading_error -= 360;
  }
  else if(heading_error < -180) {
    heading_error += 360;
  }
  else {
    heading_error = heading_error;
  }

  if(heading_error > 0) {
    turn_direction = forward;
  }
  else if(heading_error < 0) {
    turn_direction = reverse;
  }
  else {
    turn_direction = forward; // default to forward if the error is zero
  }

  if(turn_direction == forward) {
    LeftFrontDrive.spin(reverse);
    LeftBackDrive.spin(reverse);
    RightFrontDrive.spin(forward);
    RightBackDrive.spin(forward);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    LeftFrontDrive.spin(forward);
    LeftBackDrive.spin(forward);
    RightFrontDrive.spin(reverse);
    RightBackDrive.spin(reverse);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }

  return true;
}

bool turnToHeading(directionType dir, double heading, rotationUnits units, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the turn direction determined by the 'dir' parameter 
  // instead of calculating it based on the heading error.

  // The implementation would involve spinning the motors in the 
  // specified direction until the target heading is reached, and 
  // then stopping the motors.

  directionType turn_direction = dir;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;

  if(dir == forward) {
    LeftFrontDrive.spin(reverse);
    LeftBackDrive.spin(reverse);
    RightFrontDrive.spin(forward);
    RightBackDrive.spin(forward);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(dir == reverse) {
    LeftFrontDrive.spin(forward);
    LeftBackDrive.spin(forward);
    RightFrontDrive.spin(reverse);
    RightBackDrive.spin(reverse);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}

bool turnToHeading(double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the motors spinning at the specified velocity instead 
  // of a default speed.

  // The implementation would involve spinning the motors at the 
  // specified velocity until the target heading is reached, and 
  // then stopping the motors.

  directionType turn_direction = forward;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;
  
  if(heading_error > 180) {
    heading_error -= 360;
  }
  else if(heading_error < -180) {
    heading_error += 360;
  }
  else {
    heading_error = heading_error;
  }

  if(heading_error > 0) {
    turn_direction = forward;
  }
  else if(heading_error < 0) {
    turn_direction = reverse;
  }
  else {
    turn_direction = forward; // default to forward if the error is zero
  }

  if(turn_direction == forward) {
    LeftFrontDrive.spin(reverse, velocity, units_v);
    LeftBackDrive.spin(reverse, velocity, units_v);
    RightFrontDrive.spin(forward, velocity, units_v);
    RightBackDrive.spin(forward, velocity, units_v);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(turn_direction == reverse) {
    LeftFrontDrive.spin(forward, velocity, units_v);
    LeftBackDrive.spin(forward, velocity, units_v);
    RightFrontDrive.spin(reverse, velocity, units_v);
    RightBackDrive.spin(reverse, velocity, units_v);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}

bool turnToHeading(directionType dir, double heading, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion = true) {
  // This function can be implemented similarly to the previous one, 
  // but with the turn direction determined by the 'dir' parameter 
  // instead of calculating it based on the heading error, and with 
  // the motors spinning at the specified velocity instead of a default speed.

  // The implementation would involve spinning the motors in the 
  // specified direction at the specified velocity until the target 
  // heading is reached, and then stopping the motors.

  directionType turn_direction = dir;
  double target_heading = heading;
  double current_heading = Inertial6.heading();
  double heading_error = target_heading - current_heading;

  if(dir == forward) {
    LeftFrontDrive.spin(reverse, velocity, units_v);
    LeftBackDrive.spin(reverse, velocity, units_v);
    RightFrontDrive.spin(forward, velocity, units_v);
    RightBackDrive.spin(forward, velocity, units_v);

    waitUntil(Inertial6.heading() >= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else if(dir == reverse) {
    LeftFrontDrive.spin(forward, velocity, units_v);
    LeftBackDrive.spin(forward, velocity, units_v);
    RightFrontDrive.spin(reverse, velocity, units_v);
    RightBackDrive.spin(reverse, velocity, units_v);

    waitUntil(Inertial6.heading() <= heading);

    LeftFrontDrive.stop();
    LeftBackDrive.stop();
    RightFrontDrive.stop();
    RightBackDrive.stop();
  }
  else {
    // If the direction is undefined, we can choose to do nothing or default to a specific behavior. 
    // For this implementation, we'll default to not turning if the direction is undefined.
  }

  return true;
}
*/