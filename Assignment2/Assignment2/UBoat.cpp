#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat() : Vehicle(50)
	{

	}

	UBoat::~UBoat()
	{

	}

	void UBoat::InitType()
	{
		m_type = vtUBoat;
	}

	unsigned int UBoat::GetMaxSpeed()
	{
		unsigned int speedDive = GetDiveSpeed();
		unsigned int speedSail = GetSailSpeed();

		return (speedDive > speedSail ? speedDive : speedSail);
	}

	// 잠수 시 속도
	unsigned int UBoat::GetDiveSpeed()
	{
		unsigned int speed = 500 * log((m_totalWeight + 150) / 150) + 30;
		return speed;
	}

	// 항해 시 속도
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
