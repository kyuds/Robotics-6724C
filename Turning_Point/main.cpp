#include "robot-config.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/userControlFunctions.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/supportCode.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/baseSupportCode.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/intakeSupportCode.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/frontParking.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/backAuto.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/programming.h"
#include "/Users/danielshin/Desktop/VEX/turning point/V7/reBound.h"

#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

}

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
   bFPark();
  //  programmingSkills3();
  //blueRebound();
}

void usercontrol( void ) {
  // User control code here, inside the loop
  //programmingSkills2();
  setCoast();
  vex::task driveTask = vex::task(driveControl);
  vex::task anglerTask = vex::task(angleControl);
  while (1){
      intakeControl();
      puncherControl();
      armControl();
      Brain.Screen.printAt(1,40,"%d", Sonar.distance(vex::distanceUnits::mm));
  }
}
//
// Main will set up the competition functions and callbacks.
//
int main() {

    //Run the pre-autonomous function.
    pre_auton();

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.
    while(1) {
      sleepingMili(100);
    }

}
