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

void mogoUp(){
	while(SensorValue[in3] < 3885){
		motor[port8] = 127;
	}
	motor[port8] = 0;
}

/*
void mogoUp2(){
	while(SensorValue[in3] < 3885){
		motor[port8] = 127;
		if(vexRT[Btn8D]) break;
	}
	motor[port8] = 0;
}
*/

void mogoDown(){

	while(SensorValue[in3] > 950){
		motor[port8] = -127;
	}
	wait10Msec(60);
	motor[port8] =0;
}

/*
void mogoDown2(){
	while(SensorValue[in3] > 950){
		motor[port8] - 127;
		if(vexRT[Btn8U]) break;
	}
	wait10Msec(60);
	motor[port8]=0;
}
*/

int in = 0;
int pos = 0;


void fourBarUp(){
	if(SensorValue[in4] < 4095){
		while(SensorValue[in4] < 4095) motor[port7] = 127;
		motor[port7]=0;
	}
}
void fourBarDown(){
	if(SensorValue[in4] > 2850){
		while(SensorValue[in4] > 2850) motor[port7] = -127;
		motor[port7] = 30;
		wait10Msec(10);
		motor[port7] = 0;
	}
}

void intake() {
	in = 1;
	while(SensorValue[in4] > 1816){
		motor[port7] = -127;
	}
	motor[port7] = 0;

	wait10Msec(7);
	while(SensorValue[in4] < 2640){
		motor[port7] = 127;
	}
	motor[port7]=-20;
	wait10Msec(4);
	motor[port7]=0;
	in = 0;
}

task intakeControl(){
	while(true){
		if(vexRT[Btn6U] == 1){
			if(pos){
				fourBarUp();
				pos =0;
			}
			else{
				fourBarDown();
				pos = 1;
			}
		}
		else if(vexRT[Btn6D] == 1){
			intake();
			pos =1;
		}
	}
}

task rollerControl(){
	while(true){
		if(vexRT[Btn5U] && vexRT[Btn5D]){
			motor[port6] = -127;
		}
		else if(pos == 1 && vexRT[Btn5D]){
			motor[port6] = 127;
		}
		else if(pos == 1 && vexRT[Btn5U]){
			motor[port6] = 50;
		}
		else if(in == 1){
			motor[port6] = 127;
		}
		else if(vexRT[Btn7U]) motor[port6]=-127;
		else motor[port6] = 30;
	}
}

task deploy(){
	motor[port3]=motor[port4]=127;
	wait10Msec(30);
	motor[port3]=motor[port4]=10;
	mogoUp();
}
task down(){
	mogoUp();
}

task intaking(){
	mogoDown();
}

task upGo(){
	motor[port3]=motor[port4]=127;
	wait10Msec(20);
	motor[port3]=motor[port4]=0;

	fourBarUp();
	motor[port3]= motor[port4]=-127;
	wait10Msec(40);
	motor[port6]=-127;

	motor[port3]=motor[port4]=127;
	wait10Msec(23);
	motor[port3]=motor[port4]=0;

}
