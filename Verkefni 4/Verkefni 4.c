#pragma config(Sensor, in2,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl5,  sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                 - Forward until Close Proximity -                                  *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  The Program Will Only work during the day or when the light is on becouse the lightSensor will    *|
|*  Detect it and tell the robot to start moving when it moves then when it gets within 63cm then it  *|
|*  stops and it will turn to the left then start moving again                                        *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  The Ultrasonic Sensor returns a value of '-1' when it is out of range from the nearest      *|
|*        object.  The range is from 0 to 255 inches, so make sure that the robot is within this      *|
|*        range or it may never run.                                                                  *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 9,10 sonarSensor         VEX Sonar Sensor      Front mounted, facing forward     *|
\*-----------------------------------------------------------------------------------------------4246-*/






task main()
{
	wait1Msec(200);						// Robot waits for 2000 milliseconds before executing program
		while(SensorValue(sonarSensor) = True)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			motor[rightMotor] = 124;			// Motor on port2 is run at half (63) power forward
			motor[leftMotor]  = 124;
			if(SensorValue(lightSensor) > 300)
			{
				motor[rightMotor] = 0;			// Motor on port2 is run at half (63) power forward
				motor[leftMotor]  = 0;
				}
			if (SensorValue(sonarSensor) < 69 || SensorValue(sonarSensor) == -1)
				motor[rightMotor] = -123;			// Motor on port2 is run at half (63) power forward
				motor[leftMotor]  = 123;

		// Motor on port3 is run at half (63) power forward
		}
	}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++