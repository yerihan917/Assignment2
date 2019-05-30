#include "Vehicle.h" 
#include "DeusExMachina.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		m_type = vtInvalid;

		m_maxPassengerCount = maxPassengersCount;
		m_passengerCount = 0;

		m_totalWeight = 0;
		m_position = 0;

		m_passengers = new const Person * [maxPassengersCount];
		memset(m_passengers, 0, sizeof(m_passengers));

		m_moveCount = 0;
		m_sleepCount = 0;
	}

	Vehicle::~Vehicle()
	{
		FreeAllPassengers();
	}

	void Vehicle::InitMoveAndSleepCount()
	{
		m_moveCount = DEUS_EX_MACHINA->GetMoveCount(m_type);
		m_sleepCount = 0;
	}

	void Vehicle::FreePerson(const Person** person)
	{
		_ASSERT(person != NULL);

		if (*person != NULL)
		{
			delete* person;
			*person = NULL;
		}
	}

	void Vehicle::FreeAllPassengers()
	{
		if (m_passengers != NULL)
		{
			for (unsigned int i = 0; i < m_passengerCount; ++i)
			{
				FreePerson(&m_passengers[i]);
			}

			delete[] m_passengers;
			m_passengers = NULL;
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (m_passengerCount >= m_maxPassengerCount || person == NULL)
		{
			return false;
		}

		m_passengers[m_passengerCount++] = person;
		m_totalWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int index)
	{
		if (m_passengerCount <= index)
		{
			return false;
		}

		m_totalWeight -= m_passengers[index]->GetWeight();
		FreePerson(&m_passengers[index]);

		for (unsigned int i = index; i < --m_passengerCount; ++i)
		{
			m_passengers[i] = m_passengers[i + 1];
		}
		m_passengers[m_passengerCount] = NULL;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return m_passengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return m_maxPassengerCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int index) const
	{
		if (m_passengerCount <= index)
		{
			return NULL;
		}

		return m_passengers[index];
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		return m_totalWeight;
	}

	unsigned int Vehicle::GetPosition() const
	{
		return m_position;
	}

	unsigned int Vehicle::GetMoveCount() const
	{
		return m_moveCount;
	}

	unsigned int Vehicle::GetSleepCount() const
	{
		return m_sleepCount;
	}

	void Vehicle::GetOffAllPassengers()
	{
		for (unsigned int i = 0; i < m_passengerCount; ++i)
		{
			m_passengers[i] = NULL;
		}

		m_passengerCount = 0;
	}

	bool Vehicle::Move()
	{
		// Travel() È£Ãâ ½Ã È£ÃâµÇ´Â ÇÔ¼ö
		if (m_type > vtInvalid && m_type < vtCount)
		{

			if (m_moveCount != 0)
			{
				m_position += GetMaxSpeed();
				--m_moveCount;

				// moving È½¼ö ´Ù½è´Ù, ÀÌÁ¦ ½¯ Â÷·Ê´Ù.
				if (m_moveCount == 0)
				{
					m_sleepCount = DEUS_EX_MACHINA->GetSleepCount(m_type);
				}

				return true;
			}
			else if (m_sleepCount != 0)
			{
				--m_sleepCount;

				// sleep È½¼ö ´Ù½è´Ù. ÀÌÁ¦ ¿òÁ÷ÀÏ Â÷·Ê´Ù.
				if (m_sleepCount == 0)
				{
					m_moveCount = DEUS_EX_MACHINA->GetMoveCount(m_type);
				}

				return false;
			}
		}

		return false;
	}
}
