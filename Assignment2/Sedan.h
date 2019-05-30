#pragma once

#include "Common.h"

namespace assignment2
{
	class Trailer;

	// [도로 주행] 가능
	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		virtual unsigned int GetMaxSpeed();

		virtual unsigned int GetDriveSpeed();

	private:
		void FreeTrailer();

	private:
		const Trailer* m_trailer;
	};
}

