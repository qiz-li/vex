#include "vex.h"
using namespace vex;

// When running, it is very **important**
// to start the robot exactly 1 metre from the ball
// with the claw fulling opened.
int main()
{
  // Initialize robot config
  vexcodeInit();

  // Raise arm so it does not get stuck in hoop
  Arm.spinFor(forward, 50, degrees);

  Drivetrain.driveFor(forward, 1000, mm);

  // Grab ball
  Claw.spinFor(reverse, 180, degrees);
  // So the ball doesn't get stuck on hoop
  Arm.spinFor(forward, 15, degrees);

  // Get out of hoop
  Drivetrain.driveFor(reverse, 500, mm);

  // Raise arm
  Arm.spinFor(forward, 600, degrees);
  Drivetrain.driveFor(forward, 500, mm);

  // Drop ball
  Claw.spinFor(forward, 180, degrees);
}
