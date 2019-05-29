#pragma once

#include "Common.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	// [항해] 가능
	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		Boatplane operator+(Airplane& plane);

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetSailSpeed();

	private:
		virtual void InitType();
	};
}
