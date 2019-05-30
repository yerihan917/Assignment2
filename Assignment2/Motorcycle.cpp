#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle() : Vehicle(2)
	{
		m_type = vtMotorcycle;
		InitMoveAndSleepCount();
	}

	Motorcycle::~Motorcycle()
	{

	}

	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	// 도로 주행 시 속도
	unsigned int Motorcycle::GetDriveSpeed()
	{
		int preCalc = (int)((-1) * (m_totalWeight / 15));
		int speed = (int)(pow(preCalc, 3) + (m_totalWeight * 2) + 400);

		if (speed > 0)
		{
			return (unsigned int)speed;
		}

		return (unsigned int)0;
	}
}
