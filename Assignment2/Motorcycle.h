#pragma once

#include "Common.h"

namespace assignment2
{
	// [도로 주행] 가능
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetDriveSpeed();
	};
}
