vex::brain Brain;
vex::controller Primary = vex::controller(vex::controllerType::primary);

// motors

vex::motor RF = vex::motor(vex::PORT19,true);
vex::motor RB = vex::motor(vex::PORT20,true);
vex::motor LF = vex::motor(vex::PORT11,false);
vex::motor LB = vex::motor(vex::PORT12,false);

vex::motor Cap = vex::motor(vex::PORT13,false);
vex::motor Angler = vex::motor(vex::PORT10,true);
vex::motor Shooter = vex::motor(vex::PORT16,true);
vex::motor Intake = vex::motor(vex::PORT15,true);

// sensors
vex::limit leftIntake = vex::limit(Brain.ThreeWirePort.A);
vex::limit rightIntake = vex::limit(Brain.ThreeWirePort.B);

vex::sonar Sonar = vex::sonar(Brain.ThreeWirePort.H);
