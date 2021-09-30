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
void redBack(void);
void bFPark(void);

// auton functions

void redBack(void){
  Shooter.rotateFor(170,vex::rotationUnits::deg, 100, PCT, false);
  Intake.spin(FWD, 95, PCT);
  goForward(2000);
  vex::task::sleep(200);
  goBackward(2100);
  vex::task check_stack = vex::task(doubleStack);
  vex::task::sleep(500);
  turnRight_Slow(640);
  vex::task::sleep(200);
  spinBase(-30, 30);
  vex::task::sleep(60);
  goForward(1200);
  vex::task::sleep(200);
  turnLeft_Slow(263);
  vex::task::sleep(4000);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, true);

  turnLeft_Slow(370);
  vex::task::sleep(200);
  spinBase(30, -30);
  vex::task::sleep(60);
  goForward(2500);
}

void blueBack(void){
  Shooter.rotateFor(180,vex::rotationUnits::deg, 100, PCT, false);
  Intake.spin(FWD, 95, PCT);
  goForward(2000);
  vex::task::sleep(200);
  goBackward(2100);
  vex::task check_stack = vex::task(doubleStack);
  vex::task::sleep(500);
  turnLeft_Slow(640);
  vex::task::sleep(200);
  spinBase(30, -30);
  vex::task::sleep(60);
  goForward(1200);
  vex::task::sleep(200);
  turnRight_Slow(250);
  vex::task::sleep(4000);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, true);

  turnRight_Slow(380);
  vex::task::sleep(200);
  spinBase(-30, 30);
  vex::task::sleep(60);
  goForward(2500);
}
