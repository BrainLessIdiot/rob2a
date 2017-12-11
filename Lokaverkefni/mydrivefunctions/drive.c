void remote(){
	while(vexRT[Btn8D] == 0)
	{
		motor[rightMotor]=vexRT[Ch1];
		motor[leftMotor]=vexRT[Ch2];

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
			motor[udMotor] = 127;

		}
		else if(vexRT[Btn5D]== 1)
		{
			motor[udMotor]= -127;
		}
		else
		{
			motor[udMotor]= 0;
		}
	}

}

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
	wait1Msec(BASETIME*i);
}

void drive_forward(int i)
{
	motor[rightMotor] = 127;
	motor[leftMotor]  = 107;
	wait1Msec(BASETIME*i);
}
