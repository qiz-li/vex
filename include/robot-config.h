using namespace vex;

using signature = vision::signature;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor Arm;
extern motor Claw;
extern optical Sight;

// Vision sensor (currently deactivated)
// extern vision Sight;
// extern signature vision__BLUE_BALL;
// extern signature vision__RED_BALL;
// extern signature vision__SIG_3;
// extern signature vision__SIG_4;
// extern signature vision__SIG_5;
// extern signature vision__SIG_6;
// extern signature vision__SIG_7;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);