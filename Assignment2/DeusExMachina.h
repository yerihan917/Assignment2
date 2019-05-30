#pragma once 

#include "Vehicle.h" 

namespace assignment2
{
	const unsigned int maxVehicleCount = 10;

	// ½Ì±ÛÅæ Å¬·¡½º
	class DeusExMachina
	{
	public:
		~DeusExMachina();

		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int index);
		const Vehicle* GetFurthestTravelled() const;

		unsigned int GetMoveCount(vehicleType type) const;
		unsigned int GetSleepCount(vehicleType type) const;

		unsigned int GetVehicleCount() const { return m_vehicleCount; }	// for Test
		Vehicle* GetVehicle(unsigned int index) const { return (index >= m_vehicleCount ? NULL : m_vehicles[index]); }	// for Test

	private:
		DeusExMachina();
		void SetMoveAndSleepCount();

		void FreeVehicle(Vehicle** vehicle);

	private:
		static DeusExMachina* m_instance;

		unsigned int m_vehicleCount;
		Vehicle* m_vehicles[maxVehicleCount];

		unsigned int m_moveCountForType[vtCount];
		unsigned int m_sleepCountForType[vtCount];
	};

	#define DEUS_EX_MACHINA DeusExMachina::GetInstance()
}
