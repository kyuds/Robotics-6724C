#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

////////////////////////////////////////////////////
//                                                //
//          Team 6724C Support Code               //
//                                                //
//      Autonomous Support Functions              //
//      1. Drive Straight                         //
//      2. Slow Down                              //
//      3. Turn Left / Right                      //
//                                                //
////////////////////////////////////////////////////

void goForward(int ticks, bool slide = true){
  int goalRight = rightEnco() + ticks;
  int goalLeft = leftEnco() + ticks;

  while(goalRight > rightEnco() && goalLeft > leftEnco()){
    spinBase(80, 80);
  }
  if(slide){
    for(int i = 79; i > 18; i -= 2){
      spinBase(i, i);
      sleepingMili(10);
    }
  }
  holdBase();
  Brain.Screen.printAt(1,40,"%d", rightEnco());
}
void goForward_Slow(int ticks, bool slide = true){
  int goalRight = rightEnco() + ticks;
  int goalLeft = leftEnco() + ticks;

  while(goalRight > rightEnco() && goalLeft > leftEnco()){
    spinBase(60, 60);
  }
  if(slide){
    for(int i = 59; i > 18; i -= 1){
      spinBase(i, i);
      sleepingMili(10);
    }
  }
  holdBase();
  Brain.Screen.printAt(1,40,"%d", rightEnco());
}
void goBackward(int ticks, bool slide = true){
  int goalRight = rightEnco() - ticks;
  int goalLeft = leftEnco() - ticks;

  while(goalRight < rightEnco() && goalLeft < leftEnco()){
    spinBase(-80, -80);
  }
  if(slide){
    for(int i = 79; i > 18; i-=2){
      spinBase((-1) * i, (-1) * i);
      sleepingMili(10);
    }
  }
  holdBase();
  Brain.Screen.printAt(1,40,"%d", rightEnco());
}
void goBackward_Slow(int ticks, bool slide = true){
  int goalRight = rightEnco() - ticks;
  int goalLeft = leftEnco() - ticks;

  while(goalRight < rightEnco() && goalLeft < leftEnco()){
    spinBase(-60, -60);
  }
  if(slide){
    for(int i = 59; i > 18; i-=1){
      spinBase((-1) * i, (-1) * i);
      sleepingMili(10);
    }
  }
  holdBase();
  Brain.Screen.printAt(1,40,"%d", rightEnco());
}

void turnRight(int ticks){
  int goalRight = rightEnco() + ticks;
  while(goalRight > rightEnco()){
    spinBase(70, -70);
  }
  holdBase();
}

void turnLeft(int ticks){
  int goalLeft = leftEnco() + ticks;
  while(goalLeft > leftEnco()){
    spinBase(-70, 70);
  }
  holdBase();
}
void turnRight_Slow(int ticks){
  int goalRight = rightEnco() + ticks;
  while(goalRight > rightEnco()){
    spinBase(50, -50);
  }
  holdBase();
}

void turnLeft_Slow(int ticks){
  int goalLeft = leftEnco() + ticks;
  while(goalLeft > leftEnco()){
    spinBase(-50, 50);
  }
  holdBase();
}
