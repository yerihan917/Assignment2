#pragma once

#include "Common.h"

namespace assignment2
{
	// [���� ����] ����
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		~Motorcycle();

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetDriveSpeed();
	};
}
