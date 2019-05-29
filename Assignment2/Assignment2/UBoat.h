#pragma once

#include "Common.h"

namespace assignment2
{
	// [���, ����] ����
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetDiveSpeed();
		virtual unsigned int GetSailSpeed();

	private:
		virtual void InitType();
	};
}
