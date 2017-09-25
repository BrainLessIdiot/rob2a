#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                              - Forward for Distance with Encoders -                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward and backwards using shaft encoders               *|
|*                                                                                                    *|
|*
\*----------------------------------------------------------------------------------------------------*/
//  2*3,14*5,15=32,3cm (The wheel travels 32,3cm in one rotation)
// Calculating how many rotations to travel 50cm: 50/32,342=1,55
// And to get the degrees: 1,55*360=557

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
const int ROTATION=557;
void drive_forward(int i)
{
	while(abs(SensorValue[leftEncoder]) < ROTATION*i){
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
}
void drive_backward(int i)
{
	while(abs(SensorValue[leftEncoder]) < ROTATION*i){
		motor[rightMotor] = -63;
		motor[leftMotor] = -63;
	}
}
void reset_encoder(){
	SensorValue[leftEncoder]=0;
	SensorValue[rightEncoder]=0;
}

task main()
{
	wait1Msec(2000);
	for(int i = 1; i<6;i++){
		reset_encoder();
		drive_forward(i);
		reset_encoder();
		drive_backward(i);
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++