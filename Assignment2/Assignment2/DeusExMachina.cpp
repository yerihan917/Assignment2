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
			Airplane �� �� �� �̵��� ��, �� �� ���� ���ϴ�.
			Boat �� �� �� �̵��� ��, �� �� ���� ���ϴ�.
			Boatplane �� �� �� �̵��� ��, �� �� ���� ���ϴ�.
			Motorcycle �� �ټ� �� �̵��� ��, �� �� ���� ���ϴ�.
			Ʈ���Ϸ��� �޷� ���� ���� Sedan �� �ټ� �� �̵��� ��, �� �� ���� ���ϴ�.
			Ʈ���Ϸ��� �޷� �ִٸ�, �ټ� �� �̵��� ��, �� �� ���� ���ϴ�.
			UBoat �� �� �� �̵��� ��, �� �� ���� ���ϴ�
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

		// ��� ����� ���������� �ּ� ù ��° ���� vehicle ��ȯ
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
