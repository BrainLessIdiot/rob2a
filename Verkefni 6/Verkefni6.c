#pragma config(Sensor, in1,    PotentioSensor, sensorPotentiometer)
#pragma config(Sensor, in3,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  gyro,           sensorNone)
#pragma config(Sensor, dgtl5,  inputSonar,     sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  Button,         sensorTouch)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port2,           armMotor,      tmotorVex269, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This program allows a Robot to fallow a line by determening if the line is black or white by using sensor *\\
// underneath the robot if there is white it will either turn left or right depending on wich sensor is      	\\
// triggered like if the right sensor is triggered then it will go to the left and so on if you press the    	\\
// button in front of the robot then it will stop all tasks.
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
const int POTENTIO = 1760;
const int BASETIME = 450;
//(920)

void follow_line(int i)
{
	wait1Msec(200);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 2500;
  int threshold2 = 2700;    /* found by taking a reading on both DARK and LIGHT    */
                        /* surfaces, adding them together, then dividing by 2. */

  while(SensorValue(Button) < 1 && SensorValue(inputSonar) > 18)
  {
    // RIGHT sensor sees dark:
   if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 80;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold2)
    {
      // go straight
      motor[leftMotor]  = 80;
      motor[rightMotor] = 80;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 80;
    }
 }


}

void arm_down()
{
			motor[armMotor] = 30;
			wait1Msec(1000);
			motor[armMotor] = -10;

}

void arm_up()
{

		motor[armMotor] = -100;
		wait1Msec(1500);
}

void claw_close()
{
		wait1Msec(1000);
		motor[clawMotor] = 40;
		wait1Msec(1000);
}
void claw_open()
{
	motor[clawMotor] = -40;
	wait1Msec(1000);
}

void turn_around()
{
	motor[leftMotor] = -40;
	motor[rightMotor] = 40;
	wait1Msec(1000);
}



task main()
{
	while (SensorValue(inputSonar) > 18)
	{
		follow_line(i);
	}
	claw_open();
	arm_down();
	claw_close();
	arm_up();
	turn_around();
}
