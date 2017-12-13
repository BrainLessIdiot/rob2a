

void forward()
{

	wait1Msec(2000);

	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;

	//While less than 1000 encoder counts of the right motor
	while(nMotorEncoder[rightMotor] < 1000)
	{
		//Move forward at half power
		motor[rightMotor] = 63;
		motor[leftMotor]	= 63;
	}

  //Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;

	//While less than 1000 encoder counts of the right motor
	while(nMotorEncoder[rightMotor] > -1000)
	{
		//Move in reverse at half power
		motor[rightMotor] = -63;
		motor[leftMotor]	= -63;
	}
}

void drive_backward(int i)
{
	motor[rightMotor] = -117;
	motor[leftMotor]  = -127;
	wait1Msec(BASETIME2*i);
}

void drive_forward(int i)
{
	motor[rightMotor] = 127;
	motor[leftMotor]  = 107;
	wait1Msec(BASETIME2*i);
}
void forward2()
{

	wait1Msec(200);
			while(SensorValue(sonarSensor) = True)
			{
				motor[rightMotor] = 124;
				motor[leftMotor]  = 124;
				if(SensorValue(lightSensor) > 300)
				{
					motor[rightMotor] = 0;
					motor[leftMotor]  = 0;
					}
				if (SensorValue(sonarSensor) < 69 || SensorValue(sonarSensor) == -1)
				{
					motor[rightMotor] = -123;
					motor[leftMotor]  = 123;
			}

			}
	}
void remote()
{
	while(1==1)
{
	motor[rightMotor]=vexRT[Ch2];
	motor[leftMotor]=vexRT[Ch1];

	if(vexRT[Btn6U]==1)
	{
		motor[clawMotor] = 127;

	}
	else if(vexRT[Btn6D]== 1)
	{
		motor[clawMotor]= -127;
	}
	else
	{
	motor[clawMotor]= 0;
	}

	if(vexRT[Btn5U]==1)
	{
		motor[armMotor] = 127;

	}
	else if(vexRT[Btn5D]== 1)
	{
		motor[armMotor]= -127;
	}
	else
	{
	motor[armMotor]= 0;
	}
}


}


void verkefni5()
{
	 wait1Msec(200);

  int threshold = 2500;
  int threshold2 = 2700;

  while(SensorValue[Button] < 1)
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+


    if(SensorValue(lineFollowerRIGHT) > threshold)
    {

      motor[leftMotor]  = 120;
      motor[rightMotor] = 0;
    }

    if(SensorValue(lineFollowerCENTER) < threshold2)
    {

      motor[leftMotor]  = 120;
      motor[rightMotor] = 120;
    }

    if(SensorValue(lineFollowerLEFT) > threshold)
    {

      motor[leftMotor]  = 0;
      motor[rightMotor] = 120;
    }

}

}


	void follow_line(int i)
	{
		wait1Msec(200);




	  while(SensorValue(sonarSensor) > 19)
	  {

	   if(SensorValue(lineFollowerRIGHT) > threshold)
	    {

	      motor[leftMotor]  = 80;
	      motor[rightMotor] = 0;
	    }

	    if(SensorValue(lineFollowerCENTER) > threshold2)
	    {

	      motor[leftMotor]  = 80;
	      motor[rightMotor] = 80;
	    }

	    if(SensorValue(lineFollowerLEFT) > threshold)
	    {

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
			wait1Msec(900);
			motor[armMotor] = -50;
			wait1Msec(300);
			motor[armMotor] = -20;


	}

	void claw_close()
	{
			wait1Msec(1000);
			motor[clawMotor] = 40;
			wait1Msec(1000);
	}
	void claw_open()
	{
		wait1Msec(1000);
		motor[clawMotor] = -40;
		wait1Msec(1000);
	}

	void turn_around(int i)
	{
		wait1Msec(1000);
		motor[leftMotor] = 120;
		motor[rightMotor] = -90;
		wait1Msec(BASETIME*i);

	}
	void stop_motor()
	{
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
	}
