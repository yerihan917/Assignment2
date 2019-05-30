#pragma once

#include "Common.h"
#include "Boatplane.h"

namespace assignment2
{
	class Boat; 
	
	// [도로 주행, 비행] 가능
	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		Boatplane operator+(Boat& boat);

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetDriveSpeed();
		virtual unsigned int GetFlySpeed();

		Boatplane CombineToBoatplane(Boat& boat, bool boatFirst = false);
	};
}
