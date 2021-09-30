#define FWD vex::directionType::fwd
#define REV vex::directionType::rev
#define PCT vex::velocityUnits::pct
#define HOLD vex::brakeType::hold
#define COAST vex::brakeType::coast

////////////////////////////////////////////////////
//                                                //
//          Team 6724C UserControl                //
//                                                //
//      DriverControl Support Functions           //
//      1. drive control                          //
//      2. angleControl                           //
//      3. intakeControl                          //
//      4. puncherControl                         //
//      5. armControl                             //
//      6. setCoast                               //
//        -> this setCoast resets base            //
//                                                //
////////////////////////////////////////////////////

int driveControl(void){
    int right, left;
    while(1){
        right = Primary.Axis2.value();
        left = Primary.Axis3.value();

        if(abs(right) < 8) right = 0;
        if(abs(left) < 8) left = 0;

        RF.spin(FWD, right, PCT);
        RB.spin(FWD, right, PCT);
        LF.spin(FWD, left, PCT);
        LB.spin(FWD, left, PCT);
    }

    return 0;
}

int angleControl(void){
    int switcher = 0;
    while(true){
        if(Primary.ButtonR1.pressing()){
            while(Primary.ButtonR1.pressing()){}
            if(switcher == 0) switcher = 1;
            else switcher = 0;

            if(switcher == 0) Angler.rotateFor(-160,vex::rotationUnits::deg, 100, PCT);
            else if(switcher == 1) Angler.rotateFor(160,vex::rotationUnits::deg, 100, PCT);
        }
        else Angler.stop(HOLD);
    }
    return 0;
}

void intakeControl(void){
    if(Primary.ButtonL1.pressing()) Intake.spin(FWD, 100, PCT);
    else if(Primary.ButtonL2.pressing()) Intake.spin(REV, 70, PCT);
    else Intake.stop(COAST);
}

void puncherControl(void){
    if(Primary.ButtonR2.pressing()) Shooter.spin(FWD, 100, PCT);
    else Shooter.stop(COAST);
}

void armControl(void){
    if(Primary.ButtonX.pressing()) Cap.spin(FWD, 100, PCT);
    else if(Primary.ButtonB.pressing()) Cap.spin(REV, 100, PCT);
    else Cap.stop(HOLD);
}

void setCoast(void){
    RF.stop(COAST);
    RB.stop(COAST);
    LF.stop(COAST);
    LB.stop(COAST);
}
