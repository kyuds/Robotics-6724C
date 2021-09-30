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

int leftEnc(){
	return SensorValue[dgtl3] * -1;
}
int rightEnc(){
	return SensorValue[dgtl1] * -1;
}
void resetEnco(){
	SensorValue[dgtl1] = 0;
	SensorValue[dgtl3] = 0;
}

void PFront(int tickGoal, int endP = 0, bool correct = true){
	resetEnco();
	float kp = 0.5;
	int errorLeft;
	int errorRight;

	float kpC = 0.01;
	int balanceError;

	int rightSide, leftSide;
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=127;
	while(rightEnc() < tickGoal){
		errorLeft = tickGoal - leftEnc();
		errorRight = tickGoal - rightEnc();

		balanceError = (rightEnc() - leftEnc()) * kpC;

		rightSide = errorRight * kp - balanceError;
		if(rightSide > 14) rightSide = rightSide - 9;
		leftSide  = errorLeft  * kp + balanceError;
		motor[port1]=motor[port2] = rightSide;
		motor[port9]=motor[port10]= leftSide;

		wait1Msec(20);
	}
	if(correct){
		motor[port1]=motor[port2]=motor[port9]=motor[port10] = -30;
		wait10Msec(7);
	}
	motor[port1]=motor[port2]=motor[port9]=motor[port10] = endP;
}

void PBack(int tickGoal){

	tickGoal = abs(tickGoal) * -1;
	resetEnco();
	float kp = 0.5;
	int errorLeft;
	int errorRight;

	float kpC = 0.01;
	int balanceError;

	int rightSide, leftSide;

	while(rightEnc() > tickGoal){
		errorLeft = tickGoal - leftEnc();
		errorRight = tickGoal - rightEnc();

		balanceError = (rightEnc() - leftEnc()) * kpC;

		rightSide = errorRight * kp - balanceError;
		if(rightSide > 14) rightSide = rightSide + 14;
		leftSide  = errorLeft  * kp + balanceError;
		motor[port1]=motor[port2] = rightSide;
		motor[port9]=motor[port10]= leftSide;

		wait1Msec(20);
	}
	motor[port1]=motor[port2]=motor[port9]=motor[port10] = 0;
}

void turnDegreesRight(int degrees, int speed = 70){
	float dig = 200;
	// dig conversion
	dig = (degrees * 22.6) / 10;

	resetEnco();
	motor[port1]=motor[port2]= -1 * speed;
	motor[port9]=motor[port10]=speed;

	while(SensorValue[dgtl1] < dig || SensorValue[dgtl3] > -1 * dig){
		if(SensorValue[dgtl1] > dig) motor[port1]=motor[port2]=0;
		if(SensorValue[dgtl3] < -1 * dig) motor[port9]=motor[port10]=0;
	}
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;
}

void turnDegreesLeft(int degrees, int speed = 70){
	float dig = 200;
	dig = (degrees * 22.6) / 10;

	resetEnco();
	motor[port1]=motor[port2]=speed;
	motor[port9]=motor[port10]= -1 * speed;

	while(SensorValue[dgtl3] < dig || SensorValue[dgtl1] > -1 * dig){
		if(SensorValue[dgtl3] > dig) motor[port9]=motor[port10]=0;
		if(SensorValue[dgtl1] < -1 * dig) motor[port1]=motor[port1]=0;
	}
	motor[port1]=motor[port2]=motor[port9]=motor[port10]=0;
}
void gyroPos (int pos){
	if(SensorValue[in5] > pos + 100){
		while(SensorValue[in5] > pos + 100){
			motor[port1]=motor[port2]  = -127;
			motor[port9]=motor[port10] = 127;
		}
		motor[port1]=motor[port2] = 30;
		motor[port9]=motor[port10] = -30;
	}
	else if(SensorValue[in5] < pos-100){
		while(SensorValue[in5] < pos-100){
			motor[port1]=motor[port2]=127;
			motor[port9]=motor[port10]=-127;
		}
		motor[port1]=motor[port2]=-30;
		motor[port9]=motor[port10]=30;
	}
	wait10Msec(3);
	motor[port1]=motor[port2]=motor[port9]=motor[port10] = 0;
}
