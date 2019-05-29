#include "DeusExMachina.h" 

namespace assignment2
{
	DeusExMachina* DeusExMachina::m_instance = NULL;

	DeusExMachina::DeusExMachina()
	{
		m_vehicleCount = 0;

		memset(m_vehicles, 0, sizeof(m_vehicles));

		SetMoveAndSleepCount();
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < m_vehicleCount; ++i)
		{
			FreeVehicle(&m_vehicles[i]);
		}

		if (m_instance != NULL)
		{
			delete m_instance;
		}
	}

	void DeusExMachina::FreeVehicle(Vehicle** vehicles)
	{
		_ASSERT(vehicles != NULL);

		if (*vehicles != NULL)
		{
			delete *vehicles;
			*vehicles = NULL;
		}
	}

	void DeusExMachina::SetMoveAndSleepCount()
	{
		/*
			Airplane 은 한 번 이동한 후, 꼭 세 번을 쉽니다.
			Boat 는 두 번 이동한 후, 꼭 한 번을 쉽니다.
			Boatplane 은 한 번 이동한 후, 꼭 세 번을 쉽니다.
			Motorcycle 은 다섯 번 이동한 후, 꼭 한 번을 쉽니다.
			트레일러가 달려 있지 않은 Sedan 은 다섯 번 이동한 후, 꼭 한 번을 쉽니다.
			트레일러가 달려 있다면, 다섯 번 이동한 후, 꼭 두 번을 쉽니다.
			UBoat 는 두 번 이동한 후, 꼭 네 번을 쉽니다
		*/
		for (unsigned int i = 0; i < vtCount; ++i)
		{
			m_moveCountForType[i] = 0;
			m_sleepCountForType[i] = 0;
		}

		m_moveCountForType[vtAirplane] = 1;
		m_sleepCountForType[vtAirplane] = 3;

		m_moveCountForType[vtBoat] = 2;
		m_sleepCountForType[vtBoat] = 1;

		m_moveCountForType[vtBoatplane] = 1;
		m_sleepCountForType[vtBoatplane] = 3;

		m_moveCountForType[vtMotorcycle] = 5;
		m_sleepCountForType[vtMotorcycle] = 1;

		m_moveCountForType[vtSedan] = 5;
		m_sleepCountForType[vtSedan] = 1;

		m_moveCountForType[vtSedanWithTrailer] = 5;
		m_sleepCountForType[vtSedanWithTrailer] = 2;

		m_moveCountForType[vtUBoat] = 2;
		m_sleepCountForType[vtUBoat] = 4;
	}

	unsigned int DeusExMachina::GetMoveCount(vehicleType type)
	{
		if (type <= vtInvalid || type >= vtCount)
		{
			return 0;
		}

		return m_moveCountForType[type];
	}

	unsigned int DeusExMachina::GetSleepCount(vehicleType type)
	{
		if (type <= vtInvalid || type >= vtCount)
		{
			return 0;
		}

		return m_sleepCountForType[type];
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (m_instance == NULL)
		{
			m_instance = new DeusExMachina;
		}

		return m_instance;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < m_vehicleCount; ++i)
		{
			m_vehicles[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (m_vehicleCount >= maxVehicleCount || vehicle == NULL)
		{
			return false;
		}

		m_vehicles[m_vehicleCount++] = vehicle;
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int index)
	{
		if (m_vehicleCount <= index)
		{
			return false;
		}

		FreeVehicle(&m_vehicles[index]);

		for (unsigned int i = index; i < --m_vehicleCount; ++i)
		{
			m_vehicles[i] = m_vehicles[i + 1];
		}
		m_vehicles[m_vehicleCount] = NULL;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (m_vehicleCount == 0)
		{
			return NULL;
		}

		// 모두 출발을 안했을지라도 최소 첫 번째 원소 vehicle 반환
		Vehicle* furthestVehicle = m_vehicles[0];

		for (unsigned int i = 1; i < m_vehicleCount; ++i)
		{
			if (furthestVehicle->GetPosition() < m_vehicles[i]->GetPosition())
			{
				furthestVehicle = m_vehicles[i];
			}
		}

		return furthestVehicle;
	}
}
