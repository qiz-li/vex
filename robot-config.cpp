#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 292.09999999999997, 6.858, mm, 1);
motor Arm = motor(PORT8, ratio18_1, false);
motor Claw = motor(PORT3, ratio18_1, true);
optical Sight = optical(PORT20);

/*vex-vision-config:begin*/
// signature vision__BLUE_BALL = signature(1, -2975, -2047, -2510, 7935, 10923, 9428, 5, 0);
// signature vision__RED_BALL = signature(2, 10527, 12971, 11748, -1737, -1101, -1420, 2.1, 0);
// vision Sight = vision(PORT9, 50, vision__BLUE_BALL, vision__RED_BALL);
/*vex-vision-config:end*/

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}