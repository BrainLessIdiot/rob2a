#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                      - Movement by Rotation -                                      *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses the Shaft Encoders to move forward for a certain distance. Turn 90 degrees left *|
|*  and drive forward, turn right an drive forward.                                                                                                  *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Changing the value of 'distance' will change how far your robot will travel.                *|
|*        !! 360 is equal to one full rotation of the axel !!                                         *|
|*    3)  Whichever encoder is being used for feedback should be cleared just before it starts        *|
|*        counting by using the "SensorValue(encoder) = 0;".  This helps ensure consistancy.          *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 1,2  rightEncoder        VEX Quadrature enc.   Right side encoder                *|
|*    Digital - Port 3,4  leftEncoder         VEX Quadrature enc.   Left side encoder                 *|
\*-----------------------------------------------------------------------------------------------4246-*/
//16,5/5,15=3,2


const int ROTATION=557;
float TURNBASE=3.2;
void drive_forward(int i)
{
	while(abs(SensorValue[leftEncoder]) < ROTATION && vexRT

[Btn8D] == 0){
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
}

void reset_encoder(){
	SensorValue[leftEncoder]=0;
	SensorValue[rightEncoder]=0;
}

void turn_left(int i)
{
	while(abs(SensorValue[leftEncoder]) < TURNBASE*i && vexRT[Btn8D] == 0)
	{
		motor[leftMotor]=-63;
		motor[rightMotor]=63;

	}

}
void turn_right(int i)
{
	while(abs(SensorValue[leftEncoder]) < TURNBASE*i && vexRT[Btn8D] == 0){

		motor[leftMotor]=63;
		motor[rightMotor]=-63;

	}

}

task main()
{
	while(vexRT[Btn8D] == 0){
	wait1Msec(1000);
	drive_forward(i);
	reset_encoder();
	turn_left(90);
	reset_encoder();
	drive_forward(i);
	reset_encoder();
	turn_right(90);
	reset_encoder();
	drive_forward(i);
	reset_encoder();
	turn_right(90);
	reset_encoder();
	drive_forward(i);
}

}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
