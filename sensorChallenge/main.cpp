#include "vex.h"
using namespace vex;

// Store ball color and corresponding directions
struct ball_t
{
  color color;
  turnType turnDir1;
  turnType turnDir2;
};

// Using global variables so it is easier to change them
// Often need to change because turn degrees vary based condition
const int armBin = 380;
const int clawPickup = 240;
const int ninetyDeg = 91;
const int binDeg = 44;
const int binBackDeg = 143;
const int disAfTurn = 260;
const int disBfTurn = 650;

void fillScreen();
void initialPickup();
ball_t getColor();
void toBin(ball_t ball);
void secondPickup(ball_t ball);

int main()
{
  // Initializing Robot Configuration
  vexcodeInit();

  // Pickup ball
  initialPickup();
  // Read color
  wait(1, seconds);
  ball_t ball = getColor();
  // Drop ball into bin
  toBin(ball);

  // Pickup second ball
  secondPickup(ball);
  // Read second ball color
  wait(1, seconds);
  ball = getColor();
  // Drop second ball into bin
  toBin(ball);
}

void fillScreen(color screenColor)
{
  Brain.Screen.setFillColor(screenColor);
  Brain.Screen.drawRectangle(0, 0, 480, 272);
}

void initialPickup()
{
  fillScreen(black);

  Drivetrain.setDriveVelocity(28, percent);
  Arm.setVelocity(80, percent);
  Claw.setVelocity(80, percent);

  // Prepare arm/claw to pick up ball
  // These can be async because robot will move to dispenser
  Arm.spinFor(forward, 67, degrees, false);

  // Drive to dispenser
  Drivetrain.driveFor(forward, 45, mm);
  Drivetrain.turnFor(right, ninetyDeg, degrees);
  Drivetrain.driveFor(forward, 570, mm);

  // Pickup ball
  Claw.spinFor(reverse, clawPickup, degrees);
}

ball_t getColor()
{
  ball_t ball;

  // Get color of ball
  // Directions signifies the direction of the corresponding colored bin
  if (Sight.hue() >= 100)
  {
    ball.turnDir1 = right;
    ball.turnDir2 = left;
    ball.color = blue;
  }
  else
  {
    ball.turnDir1 = left;
    ball.turnDir2 = right;
    ball.color = red;
  }

  return ball;
}

void toBin(ball_t ball)
{
  // Screen color corresponds to color
  fillScreen(ball.color);

  // Raise arm
  Arm.spinFor(forward, armBin, degrees, false);
  // Turn towards the bin
  Drivetrain.turnFor(ball.turnDir1, ninetyDeg, degrees);
  // Drive to bin
  Drivetrain.driveFor(forward, disBfTurn, mm);
  // Turn to bin
  Drivetrain.turnFor(ball.turnDir2, binDeg, degrees);
  Drivetrain.driveFor(forward, disAfTurn, mm);
  // Drop ball
  Claw.spinFor(forward, clawPickup, degrees);
}

void secondPickup(ball_t ball)
{
  // Turn back towards dispenser
  Drivetrain.driveFor(reverse, disAfTurn, mm);
  Drivetrain.turnFor(ball.turnDir2, binBackDeg, degrees);
  // Drive back to dispenser
  Drivetrain.driveFor(forward, (disBfTurn - 30), mm);
  // Turn towards dispenser
  Drivetrain.turnFor(ball.turnDir1, ninetyDeg, degrees);
  // Lower arm
  Arm.spinFor(reverse, armBin, degrees);
  // Pickup ball (again)
  Drivetrain.driveFor(forward, 100, mm);
  Claw.spinFor(reverse, clawPickup, degrees);
}
