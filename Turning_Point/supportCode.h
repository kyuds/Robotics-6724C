#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

int rightEnco(){
  return RF.rotation(vex::rotationUnits::raw);
}
int leftEnco(){
  return LF.rotation(vex::rotationUnits::raw);
}
void sleepingMili(int sleepTime){
  vex::task::sleep(sleepTime);
}
void spinBase(int right, int left){
  RF.spin(FWD, right, PCT);
  RB.spin(FWD, right, PCT);
  LF.spin(FWD, left, PCT);
  LB.spin(FWD, left, PCT);
}
void holdBase(void){
  RF.stop(HOLD);
  RB.stop(HOLD);
  LF.stop(HOLD);
  LB.stop(HOLD);
}

void coastBase(void){
  RF.stop(COAST);
  RB.stop(COAST);
  LF.stop(COAST);
  LB.stop(COAST);
}
