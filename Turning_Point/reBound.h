#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

////////////////////////////////////////////////////
//                                                //
//          Team 6724C Autonomous                 //
//                                                //
////////////////////////////////////////////////////

// auton List:
void redRebound(void);
void blueRebound(void);

// auton functions
void redRebound(void){
  Shooter.rotateFor(170,vex::rotationUnits::deg, 100, PCT, false);
  Intake.spin(FWD, 95, PCT);
  goForward(2000);
  vex::task::sleep(200);
  goBackward(2500);
  vex::task stackAgain = vex::task(doubleStack);
  vex::task::sleep(400);
  for(int i = 90; i > 18; i -= 2){
    spinBase(20, 20);
    sleepingMili(10);
  }
  holdBase();
  vex::task::sleep(400);
  turnRight_Slow(635);
  Intake.stop(COAST);
  vex::task::sleep(400);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);

  spinBase(-30, 30);
  vex::task::sleep(60);

  goForward(1800);
  turnRight(35);
  Intake.spin(FWD, 90, PCT);
  goForward(880);
  spinBase(80, 80);
  vex::task::sleep(300);
  goBackward(1100);

  vex::task::sleep(100);
  turnLeft_Slow(660);
  vex::task::sleep(100);
  Intake.spin(REV, 100, PCT);

  spinBase(30, -30);
  vex::task::sleep(60);
  goForward_Slow(1700);
  vex::task::sleep(100);
  goBackward_Slow(100);
  vex::task::sleep(100);
  turnRight_Slow(320);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);

  spinBase(-30, 30);
  vex::task::sleep(60);
  goForward(1250);
  vex::task::sleep(100);
  spinBase(100, 0);
  vex::task::sleep(1000);
  coastBase();
}

void blueRebound(void){
  Shooter.rotateFor(170,vex::rotationUnits::deg, 100, PCT, false);
  Intake.spin(FWD, 95, PCT);
  goForward(2000);
  vex::task::sleep(200);
  goBackward(2500);
  vex::task check_stack = vex::task(doubleStack);
  vex::task::sleep(400);
  for(int i = 90; i > 18; i -= 2){
    spinBase(20, 20);
    sleepingMili(10);
  }
  holdBase();
  vex::task::sleep(400);
  turnLeft_Slow(635);
  Intake.stop(COAST);
  vex::task::sleep(400);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);

  spinBase(30, -30);
  vex::task::sleep(60);

  goForward(1700);
  turnLeft(35);
  Intake.spin(FWD, 90, PCT);
  goForward(880);
  spinBase(80, 80);
  vex::task::sleep(300);
  goBackward(1100);

  vex::task::sleep(100);
  turnRight_Slow(660);
  vex::task::sleep(100);
  Intake.spin(REV, 100, PCT);

  spinBase(-30, 30);
  vex::task::sleep(60);
  goForward_Slow(1700);
  vex::task::sleep(100);
  goBackward_Slow(100);
  vex::task::sleep(100);
  turnLeft_Slow(330);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);

  spinBase(30, -30);
  vex::task::sleep(60);
  goForward(1250);
  vex::task::sleep(100);
  spinBase(0, 100);
  vex::task::sleep(1000);
  coastBase();
}
