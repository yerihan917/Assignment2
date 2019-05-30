#pragma once 

#include "Person.h" 

namespace assignment2
{
	const float e = (float)2.71;// 8281;

	enum vehicleType
	{
		vtInvalid = -1,
		vtAirplane = 0,
		vtBoat,
		vtBoatplane,
		vtMotorcycle,
		vtSedan,
		vtSedanWithTrailer,
		vtUBoat,

		vtCount
	};

	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int index);
		const Person* GetPassenger(unsigned int index) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		unsigned int GetTotalWeight() const;
		unsigned int GetPosition() const;

		unsigned int GetMoveCount() const;
		unsigned int GetSleepCount() const;

		// ¸ðµç Å¾½Â°´ ÇÏÂ÷(Only remove at container, no delete isntance)
		void GetOffAllPassengers();
		bool Move();

	protected:
		void InitMoveAndSleepCount();
		void FreeAllPassengers();

	private:
		void FreePerson(const Person** person);

	protected:
		vehicleType m_type;

		unsigned int m_maxPassengerCount;

		unsigned int m_passengerCount;
		const Person** m_passengers;

		unsigned int m_totalWeight;

		unsigned int m_position;

		unsigned int m_moveCount;
		unsigned int m_sleepCount;
	};
}
