#pragma config(Sensor, in2,    lift,           sensorPotentiometer)
#pragma config(Sensor, in3,    mobile,         sensorPotentiometer)
#pragma config(Sensor, in4,    test,           sensorPotentiometer)
#pragma config(Sensor, in5,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  right,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  left,           sensorQuadEncoder)
#pragma config(Motor,  port1,           motorRightEnc, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           motorRightY,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightLift,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           roller,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           fourbar,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           mogo,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           motorLeftY,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          motorLeftEnc,  tmotorVex393_HBridge, openLoop)

void skills(){
	// auto for 1 cone and 20 point zone.

	motor[port6]=30;
	startTask(deploy);
	wait10Msec(106);
	PFront(1300, 10, false);
	wait10Msec(3);
	mogoDown();
	wait10Msec(30);
	PBack(-1150);
	turnDegreesLeft(200);
	wait10Msec(4);
	PFront(500);
	wait10Msec(4);
	turnDegreesLeft(118);// turn to face bar
	wait10Msec(4);
	// start score
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=100;
	wait10Msec(133);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=30;
	while(SensorValue[in3] < 2850) motor[port8] = 127;
	motor[port8] = 0;
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-127;
	wait10Msec(65);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;
	//20 pt


	// stabilize
	mogoDown();
	/*motor[port1]=motor[port2]=motor[port9]=motor[port10]=30;
	wait10Msec(190);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;*/

	// start of 2nd mogo
	//PBack(200);
	turnDegreesLeft(110);

	// stabilizing process
	PFront(700);
	turnDegreesLeft(110);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-60;
	wait10Msec(130);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	// start to go for the second mobile goal
	startTask(down);
	wait10Msec(130);
	PFront(1010);
	mogoDown(); // got it.
	//face bar
	turnDegreesRight(280);
	while(rightEnc() < 150){ // approach the bar
		motor[port1]=motor[port2]=motor[port9]=motor[port10]=70;
	}
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=30;
	startTask(down);		//	Continuous
	wait10Msec(150);		//	Motion
	PBack(-880);				//	To
	mogoDown();					//	Drop the Mogo
	// done scoring 2 nd mogo
	turnDegreesRight(109); // turn to face 3rd mogo
	startTask(down);
	wait10Msec(170);
	PFront(950);
	mogoDown(); // GOT IT
	turnDegreesLeft(128); // turn to face bar
	// scoring 3rd mogo in 10pt - current expected score: 40;

	PFront(1150);					// Go TO Approach
	startTask(down);			// BAR AND
	wait10Msec(160);			// START CONTINUOUS
	PBack(-200);					// MOTION TO SCORE.

	turnDegreesRight(270); // 180 degrees turn

	// stabilize
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-70;
	wait10Msec(115);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	// to the other side of the field. for 20pt
	PFront(1900);
	startTask(intaking);
	wait10Msec(63);
	PFront(1050);

	//stabilize

	/*motor[port1]=motor[port2]=motor[port9]=motor[port10]=30;
	wait10Msec(190);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	// score 20pt

	PBack(-200);*/
	turnDegreesRight(118);

	PFront(570);
	turnDegreesLeft(110);

	motor[port1]=motor[port2]=motor[port9]=motor[port10]=127;
	wait10Msec(113);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;
	while(SensorValue[in3] < 2600) motor[port8] = 127;
	motor[port8] = 0;
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-127;
	wait10Msec(40);
	startTask(intaking);
	wait10Msec(40);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	turnDegreesRight(110);
	PFront(550);

	// final mogo

	turnDegreesRight(110);
	startTask(down);
	wait10Msec(30);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-60;
	wait10Msec(100);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	PFront(810);
	mogoDown();

	// turn to face bar
	turnDegreesLeft(280);
	PFront(850);
	startTask(down);
	wait10Msec(140);
	PBack(-600);
}

void auto_20pt_2cone(){
	motor[port6]=30;
	startTask(deploy);
	wait10Msec(106);
	PFront(1300,10);
	wait10Msec(3);
	mogoDown();
	motor[port3]=motor[port4]=-127;
	wait10Msec(45);
	motor[port3]=motor[port4]=0;
	motor[port6]=-127;
	wait10Msec(30);
	PFront(240);
	motor[port6]=127;
	intake();
	motor[port6]=30;

	startTask(upGo);

	PBack(-1400);
	/*wait10Msec(40);
	fourBarUp();
	motor[port6]=-127;



	PBack(-1400);
	startTask(upGo2);
	*/

	//startTask(upGo2);
	turnDegreesLeft(220, 127);
	wait10Msec(4);
	PFront(540);
	wait10Msec(4);
	turnDegreesLeft(118, 127);
	wait10Msec(4);
	// start score
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=95;
	wait10Msec(113);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=30;
	while(SensorValue[in3] < 2850) motor[port8] = 127;
	motor[port8] = 0;
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=-127;
	wait10Msec(65);
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;

	mogoDown();

}

void auto_5pt_2cone(){
	motor[port6]=30;
	startTask(deploy);
	wait10Msec(106);
	PFront(1300,10);
	wait10Msec(3);
	mogoDown();
	motor[port3]=motor[port4]=-127;
	wait10Msec(45);
	motor[port3]=motor[port4]=0;
	motor[port6]=-127;
	wait10Msec(30);
	PFront(240);
	motor[port6]=127;
	intake();
	motor[port6]=30;

	startTask(upGo);

	PBack(-1000);
	/*wait10Msec(40);
	fourBarUp();
	motor[port6]=-127;



	PBack(-1400);
	startTask(upGo2);
	*/

	//startTask(upGo2);
	turnDegreesLeft(300, 127);
	mogoUp();
	PBack(-300);

}
