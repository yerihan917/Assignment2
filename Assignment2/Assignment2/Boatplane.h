#pragma once

#include "Common.h"

namespace assignment2
{
	// [비행, 항해] 가능
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		Boatplane& operator=(const Boatplane& other);

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetFlySpeed();
		virtual unsigned int GetSailSpeed();

	private:
		virtual void InitType();
	};
}
