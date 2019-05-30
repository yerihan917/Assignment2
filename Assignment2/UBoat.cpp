#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() : Vehicle(50)
	{
		m_type = vtUBoat;
		InitMoveAndSleepCount();
	}

	UBoat::~UBoat()
	{

	}

	unsigned int UBoat::GetMaxSpeed()
	{
		unsigned int speedDive = GetDiveSpeed();
		unsigned int speedSail = GetSailSpeed();

		return (speedDive > speedSail ? speedDive : speedSail);
	}

	// ��� �� �ӵ�
	unsigned int UBoat::GetDiveSpeed()
	{
		unsigned int speed = (unsigned int)(500 * log((m_totalWeight + 150) / 150) + 30);
		return speed;
	}

	// ���� �� �ӵ�
	unsigned int UBoat::GetSailSpeed()
	{
		int speed = (550 - m_totalWeight) / 10;
		if (speed > 200)
		{
			return (unsigned int)speed;
		}

		return (unsigned int)200;
	}
}