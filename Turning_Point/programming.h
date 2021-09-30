#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

// programming skills function.
void programmingSkills(void){
  Shooter.rotateFor(170,vex::rotationUnits::deg, 100, PCT, false);

  // get back right ball and come back
  Intake.spin(FWD, 100, PCT);
  goForward_Slow(2100);
  vex::task::sleep(1000);
  turnRight_Slow(1000);
  vex::task::sleep(200);
  spinBase(-30, 30);
  vex::task::sleep(60);
  goBackward_Slow(1050);
  Cap.rotateFor(380, vex::rotationUnits::deg, 100, PCT);
  goForward_Slow(1050);
  Cap.rotateFor(-380, vex::rotationUnits::deg, 100, PCT, false);
  turnLeft_Slow(1050);
  vex::task::sleep(100);
  spinBase(30, -30);
  vex::task::sleep(60);
  goBackward_Slow(2400);
  vex::task::sleep(100);

  turnRight_Slow(655);
  vex::task::sleep(100);
  spinBase(-30, 30);
  vex::task::sleep(60);
  // go to shoot
  goForward_Slow(2850);
  turnLeft_Slow(650);
  goBackward_Slow(300);
  goForward_Slow(0);
  vex::task::sleep(300);
  turnRight_Slow(645);
  vex::task::sleep(300);

  //double shot
  Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  Intake.rotateFor(1000, vex::rotationUnits::deg, 100, PCT, true);
  Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);

  // get second ball
  turnLeft_Slow(650);
  vex::task::sleep(100);
  spinBase(30, -30);
  vex::task::sleep(60);

  Intake.spin(FWD, 100, PCT);

  // go forward to get second ball and shoot
  goForward_Slow(2450);
  vex::task::sleep(1000);
  Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
  turnRight_Slow(590);
  vex::task::sleep(500);
  Shooter.rotateFor(220,vex::rotationUnits::deg, 100, PCT, true);

  // go to the caps (cap #1 & 2)
  turnLeft_Slow(910);
  vex::task::sleep(100);
  spinBase(30, -30);
  vex::task::sleep(60);
  goBackward_Slow(1720);

  Cap.rotateFor(380, vex::rotationUnits::deg, 100, PCT);

  turnLeft_Slow(1000);
  vex::task::sleep(1000);
  Cap.rotateFor(-380, vex::rotationUnits::deg, 100, PCT, false);
  spinBase(30, -30);
  vex::task::sleep(70);
  goBackward_Slow(4400);
  Cap.rotateFor(300, vex::rotationUnits::deg, 100, PCT);
  Cap.rotateFor(-300, vex::rotationUnits::deg, 100, PCT);

  turnLeft_Slow(435);
  vex::task::sleep(100);
  spinBase(30, -30);
  vex::task::sleep(60);
  goBackward_Slow(2750);
  turnRight_Slow(435);
  vex::task::sleep(100);
  spinBase(-30, 30);
  vex::task::sleep(60);
  goBackward_Slow(400);
  vex::task::sleep(100);
  Intake.spin(FWD, 100, PCT);
  goForward(6000, false);
  holdBase();
  vex::task::sleep(1000);
}

void programmingSkills2(){
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
  turnRight_Slow(635);
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
  goForward(5600, false);
  holdBase();
  Intake.stop(COAST);
  vex::task::sleep(1000);
}
void programmingSkills3(){
vex::task::sleep(1000);
goBackward_Slow(2330);
vex::task::sleep(300);
turnRight_Slow(630);
vex::task::sleep(300);
spinBase(-30, 30);
vex::task::sleep(60);

// go to shooting position
goForward_Slow(3000);
turnLeft_Slow(630);
spinBase(30, -30);
vex::task::sleep(60);
goBackward_Slow(120);

goForward_Slow(0);
vex::task::sleep(200);
turnRight_Slow(645);

//double shot
Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
Intake.rotateFor(1000, vex::rotationUnits::deg, 100, PCT, true);
Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
// turn to face the second ball
turnLeft_Slow(660);
vex::task::sleep(100);
spinBase(30, -30);
vex::task::sleep(60);

// get ball
Intake.spin(FWD, 100, PCT);
goForward_Slow(2650);

// point towards cap
vex::task::sleep(200);
turnLeft_Slow(290);
vex::task::sleep(100);
spinBase(30, -30);
vex::task::sleep(60);
goBackward_Slow(1720);

vex::task::sleep(200);
// ********lift arm to flip Cap
Cap.rotateFor(380, vex::rotationUnits::deg, 100, PCT);

turnLeft_Slow(1010);
vex::task::sleep(1000);
Cap.rotateFor(-380, vex::rotationUnits::deg, 100, PCT, false);
spinBase(30, -30);
vex::task::sleep(70);
goBackward_Slow(4400);
Cap.rotateFor(300, vex::rotationUnits::deg, 100, PCT);
Cap.rotateFor(-300, vex::rotationUnits::deg, 100, PCT);

turnRight_Slow(330);
vex::task::sleep(200);
spinBase(-30, 30);
vex::task::sleep(60);
Intake.spin(FWD, 100, PCT);
Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, false);
goForward_Slow(1300);
vex::task::sleep(200);
goBackward_Slow(50);
vex::task::sleep(1000);
turnLeft_Slow(1100);
vex::task::sleep(200);
Shooter.rotateFor(350,vex::rotationUnits::deg, 100, PCT, true);
Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT, false);
Intake.rotateFor(1000, vex::rotationUnits::deg, 100, PCT, true);
Shooter.rotateFor(360,vex::rotationUnits::deg, 100, PCT, true);
Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT, true);

turnRight_Slow(640);
vex::task::sleep(200);
spinBase(-30, 30);
vex::task::sleep(60);
goBackward_Slow(1400);

turnRight_Slow(640);
vex::task::sleep(200);
spinBase(-30, 30);
vex::task::sleep(60);
goBackward_Slow(1000);
Intake.spin(FWD, 100, PCT);

turnLeft_Slow(1000);
vex::task::sleep(60);
goBackward_Slow(300);
vex::task::sleep(1000);

goForward(6050, false);
holdBase();
vex::task::sleep(1000);
}
