#include "vex.h"
using namespace vex;

void updateStat()
{
  // Overwrite old stats
  Brain.Screen.setCursor(1, 1);

  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor(white);

  // Title
  Brain.Screen.setFont(propXL);
  Brain.Screen.print("Hello World!");
  Brain.Screen.newLine();
  Brain.Screen.newLine();

  // System statistics
  Brain.Screen.setFont(monoM);
  Brain.Screen.print("Program run time: %d seconds", int(Brain.Timer.value()));
  Brain.Screen.newLine();
  Brain.Screen.print("Battery voltage: %f volts", Brain.Battery.voltage());
  Brain.Screen.newLine();
  Brain.Screen.print("Battery current: %f amp", Brain.Battery.current());
  Brain.Screen.newLine();
  Brain.Screen.print("Battery capacity: %d%%", Brain.Battery.capacity());
}

int main()
{
  // Initialize robot
  vexcodeInit();

  // Print initial stats
  updateStat();

  // Create a 'button'
  int originX = 190, originY = 165;
  int width = 100, height = 50;
  int endX = originX + width, endY = originY + height;
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawRectangle(originX, originY, width, height);

  // Put text in button
  Brain.Screen.setCursor(10, 22);
  Brain.Screen.setPenColor(white);
  Brain.Screen.print("Update");

  while (true)
  {
    // Someone touched the screen
    if (Brain.Screen.pressing())
    {

      // Position of the press
      int PressX = Brain.Screen.xPosition();
      int PressY = Brain.Screen.yPosition();

      // Press is within the 'button'
      if ((PressX >= originX && PressX <= endX) && (PressY >= originY && PressY <= endY))
      {
        updateStat();
      }
    }
  }
}
