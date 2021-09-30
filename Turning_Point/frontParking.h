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
void rFMidF(void);
void rFPark(void);
void redBack(void);
void bFMidF(void);
void bFPark(void);
void blueBack(void);

// auton functions
void rFPark(void){
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
  turnRight_Slow(645);
  Intake.stop(COAST);
  vex::task::sleep(400);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);

  spinBase(-30, 30);
  vex::task::sleep(60);

  goForward(1700);
  turnRight(35);
  Intake.spin(FWD, 90, PCT);
  goForward(880);
  vex::task::sleep(300);
  goBackward(4580);

  vex::task::sleep(100);
  turnLeft_Slow(655);
  vex::task::sleep(200);
  spinBase(30, -30);
  vex::task::sleep(60);
  goForward(3000);
  Intake.stop(COAST);
}

void bFPark(void){
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
  turnLeft_Slow(640);
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
  vex::task::sleep(300);
  goBackward(4580);

  vex::task::sleep(100);
  turnRight_Slow(655);
  vex::task::sleep(200);
  spinBase(-30, 30);
  vex::task::sleep(60);
  goForward(2900);
  Intake.stop(COAST);
}

/*
  vex::task autonCalibrate = vex::task(normal_Auton_Start_Calibration);
  goForward(1800);
  goBackward(1810);
  vex::task::sleep(500);
  turnRight(580);
  vex::task::sleep(400);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Intake.rotateFor(330, vex::rotationUnits::deg, 100, PCT, true);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);

  vex::task::sleep(1000);
  spinBase(-40, 40);
  vex::task::sleep(20);
  Intake.spin(FWD, 100, PCT);
  goForward(3700, false);
  vex::task::sleep(300);
  goBackward(1700);
  turnLeft(240);
  vex::task::sleep(200);
  goForward(1100, true);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
*/
