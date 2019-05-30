#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		m_type = vtBoatplane;
		InitMoveAndSleepCount();
	}

	Boatplane::~Boatplane()
	{

	}

	unsigned int Boatplane::GetMaxSpeed()
	{
		unsigned int speedFly = GetFlySpeed();
		unsigned int speedSail = GetSailSpeed();

		return (speedFly > speedSail ? speedFly : speedSail);
	}

	// 비행 시 속도
	unsigned int Boatplane::GetFlySpeed()
	{
		unsigned int speed = (unsigned int)round(150 * exp(((-1) * m_totalWeight + 500) / 300.0));
		return speed;
	}

	// 항해 시 속도
	unsigned int Boatplane::GetSailSpeed()
	{
		int speed = (int)(800 - (1.7 * m_totalWeight));
		if (speed > 20)
		{
			return (unsigned int)speed;
		}

		return (unsigned int)20;
	}

	Boatplane& Boatplane::operator=(const Boatplane& other)
	{
		// 대입 전에 이미 기존 승객이 있었으면? 없애자..
		FreeAllPassengers();

		m_maxPassengerCount = other.GetMaxPassengersCount();

		m_passengerCount = other.GetPassengersCount();
		m_totalWeight = other.GetTotalWeight();

		m_position = other.GetPosition();

		m_moveCount = other.GetMoveCount();
		m_sleepCount = other.GetSleepCount();

		m_passengers = new const Person * [m_maxPassengerCount];
		memset(m_passengers, 0, sizeof(m_passengers));

		for (unsigned int i = 0; i < m_passengerCount; ++i)
		{
			m_passengers[i] = other.GetPassenger(i);
		}

		return *this;
	}
}
