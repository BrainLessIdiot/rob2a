#pragma config(Sensor, in1,    potentmeter,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port2,           udMotor,       tmotorVex269, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex269, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex269, openLoop)

#include "./myheaders/myhead.h"

#include "./mydrivefunctions/drive.c"

task verk3()
{
	remote();

}
task verk1()
{
	forward();
}
task verk2()
{

}

task main()
{
	while(vexRT[Btn8D] == 0)
	{
		motor[rightMotor]=vexRT[Ch1];
		motor[leftMotor]=vexRT[Ch2];

		if(vexRT[Btn8R]==1)
		{
			startTask(verk3);

		}
		else if (vexRT[Btn8L]==1)
		{
			startTask(verk1);
		}
		else if (vexRT[Btn8U]==1)
		{
			startTask(verk2);

		}

	}

}
