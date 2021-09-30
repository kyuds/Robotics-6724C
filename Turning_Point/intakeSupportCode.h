#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

bool intakePossessBall_Thres(void){
  if(leftIntake.pressing() || rightIntake.pressing()) return true;
  else return false;
}

void intakeUntilBallPossessed(void){
  Intake.spin(FWD, 100, PCT);
  while(intakePossessBall_Thres() == false){}
  Intake.stop(HOLD);
  Intake.rotateFor(-170, vex::rotationUnits::deg, 100, PCT, false);
  Intake.stop(HOLD);
}

int normal_Auton_Start_Calibration(void){
  Shooter.rotateFor(170,vex::rotationUnits::deg, 100, PCT, false);
  intakeUntilBallPossessed();
  return 0;
}

int doubleStack(void){
  Intake.rotateFor(-600, vex::rotationUnits::deg, 100, PCT, true);
  Intake.stop(COAST);
  Intake.spin(FWD, 100, PCT);
  return 0;
}
