#include "Airplane.h"
#include "Boat.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		m_type = vtAirplane;
		InitMoveAndSleepCount();
	}

	Airplane::~Airplane()
	{

	}

	unsigned int Airplane::GetMaxSpeed()
	{
		unsigned int speedDrive = GetDriveSpeed();
		unsigned int speedFly = GetFlySpeed();

		return (speedDrive > speedFly ? speedDrive: speedFly);
	}

	// 도로 주행 시 속도
	unsigned int Airplane::GetDriveSpeed()
	{
		unsigned int speed = (unsigned int)round(4 * exp(((-1) * m_totalWeight + 400) / 70.0));
		return speed;
	}

	// 비행 시 속도
	unsigned int Airplane::GetFlySpeed()
	{
		unsigned int speed = (unsigned int)round(200 * exp(((-1) * m_totalWeight + 800) / 500.0));
		return speed;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{		
		return CombineToBoatplane(boat);
	}

	Boatplane Airplane::CombineToBoatplane(Boat& boat, bool boatFirst)
	{
		Vehicle* vehicles[2] = { this, &boat };

		unsigned int firstIndex = (boatFirst == false) ? 0 : 1;
		unsigned int secondIndex = (boatFirst == false) ? 1 : 0;

		unsigned int newMaxPassengerCount = m_maxPassengerCount + boat.GetMaxPassengersCount();

		Boatplane bp(newMaxPassengerCount);

		for (unsigned int i = 0; i < vehicles[firstIndex]->GetPassengersCount(); ++i)
		{
			const Person* person = vehicles[firstIndex]->GetPassenger(i);
			if (person != NULL)
			{
				bp.AddPassenger(person);
			}
		}

		for (unsigned int i = 0; i < vehicles[secondIndex]->GetPassengersCount(); ++i)
		{
			const Person* person = vehicles[secondIndex]->GetPassenger(i);
			if (person != NULL)
			{
				bp.AddPassenger(person);
			}
		}

		vehicles[firstIndex]->GetOffAllPassengers();
		vehicles[secondIndex]->GetOffAllPassengers();

		return bp;
	}
}
