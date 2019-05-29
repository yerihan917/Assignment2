#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle() : Vehicle(2)
	{

	}

	Motorcycle::~Motorcycle()
	{

	}

	void Motorcycle::InitType()
	{
		m_type = vtMotorcycle;
	}

	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	// 도로 주행 시 속도
	unsigned int Motorcycle::GetDriveSpeed()
	{
		int speed = (pow(-(m_totalWeight / 15), 3) + (2 * m_totalWeight) + 400);
		if (speed > 0)
		{
			return (unsigned int)speed;
		}

		return (unsigned int)0;
	}
}
