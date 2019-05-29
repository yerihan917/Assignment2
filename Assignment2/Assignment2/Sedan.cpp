#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan() : Vehicle(4)
	{
		m_trailer = NULL;
	}

	Sedan::~Sedan()
	{
		FreeTrailer();
	}

	void Sedan::InitType()
	{
		m_type = vtSedan;
	}

	unsigned int Sedan::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	// 도로 주행 시 속도
	unsigned int Sedan::GetDriveSpeed()
	{
		unsigned int speed = 0;

		if (m_totalWeight > 350)
		{
			speed = 300;
		}
		else if (m_totalWeight > 260)
		{
			speed = 380;
		}
		else if (m_totalWeight > 160)
		{
			speed = 400;
		}
		else if (m_totalWeight > 80)
		{
			speed = 458;
		}
		else
		{
			speed = 480;
		}

		return speed;
	}

	void Sedan::FreeTrailer()
	{
		if (m_trailer != NULL)
		{
			delete m_trailer;
			m_trailer = NULL;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (m_trailer != NULL || trailer == NULL)
		{
			return false;
		}

		m_trailer = trailer;
		m_totalWeight += m_trailer->GetWeight();

		m_type = vtSedanWithTrailer;

		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (m_trailer == NULL)
		{
			return false;
		}

		m_totalWeight -= m_trailer->GetWeight();

		FreeTrailer();

		m_type = vtSedan;

		return true;
	}
}
