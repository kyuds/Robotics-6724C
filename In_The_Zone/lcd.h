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

int auto_type;
int done = 0;

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

void clear(){
	clearLCDLine(0);
	clearLCDLine(1);
}

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

int lcd_select(){
	if(done) return auto_type;
	int auto_count = 0;

	displayLCDCenteredString(0, "Switch To:");
	while(nLCDButtons != centerButton){
		switch(auto_count){
			case (0): displayLCDCenteredString(1, "Driver Skills"); break;
			case (1): displayLCDCenteredString(1, "Stationary"); break;
			case (2): displayLCDCenteredString(1, "Mogo 20Pt"); break;
			case (3): displayLCDCenteredString(1, "Mogo 5Pt"); break;
			case (4): displayLCDCenteredString(1, "Programming"); break;
		}
		waitForPress();
		if(nLCDButtons == rightButton){
			if(auto_count < 4) auto_count++;
			waitForRelease();
		}
		else if(nLCDButtons == leftButton){
			if(auto_count > 0) auto_count--;
			waitForRelease();
		}
	}
	clear();
	displayLCDCenteredString(0, "Selected");

	wait10Msec(50);
	clear();
	done = 1;
	return auto_count;
}
