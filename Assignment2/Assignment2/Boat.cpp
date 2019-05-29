#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{

	}

	Boat::~Boat()
	{

	}

	void Boat::InitType()
	{
		m_type = vtBoat;
	}

	unsigned int Boat::GetMaxSpeed()
	{
		return GetSailSpeed();
	}

	// 항해 시 속도
	unsigned int Boat::GetSailSpeed()
	{
		int speed = 800 - (10 * m_totalWeight);
		if (speed > 20)
		{
			return (unsigned int)speed;
		}

		return (unsigned int)20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return plane.CombineToBoatplane(*this, true);
	}
}
