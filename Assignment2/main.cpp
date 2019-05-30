#include <cassert>
#include <iostream>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person * p2 = new Person("James", 75);
	Person * p3 = new Person("Tina", 52);
	Person * p4 = new Person("Peter", 78);
	Person * p5 = new Person("Jane", 48);
	Person * p6 = new Person("Steve", 88);

	Airplane a(5);

	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);
	
	Boat b(5);

	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);
	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina * deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina * deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;

	assert(bSame);

	Airplane * airplane = new Airplane(5);
	Boat * boat = new Boat(5);
	Boatplane * boatplane = new Boatplane(5);
	Motorcycle * motorcycle = new Motorcycle();
	Sedan * sedan = new Sedan();
	Sedan * sedan2 = new Sedan();
	UBoat * uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));

	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	bAdded = deusExMachina1->AddVehicle(airplane);
	assert(bAdded);

	deusExMachina1->AddVehicle(boat);

	deusExMachina1->AddVehicle(boatplane);
	deusExMachina1->AddVehicle(motorcycle);
	deusExMachina1->AddVehicle(sedan);
	deusExMachina1->AddVehicle(sedan2);
	deusExMachina1->AddVehicle(uboat);
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));
	deusExMachina1->AddVehicle(new Airplane(5));

	bAdded = deusExMachina1->AddVehicle(new Airplane(5));

	assert(!bAdded);

	deusExMachina1->RemoveVehicle(9);
	deusExMachina1->RemoveVehicle(8);

	bool bRemoved = deusExMachina1->RemoveVehicle(7);

	assert(bRemoved);

	bRemoved = deusExMachina1->RemoveVehicle(9);

	assert(!bRemoved);
	/*
	for (unsigned int k = 0; k < deusExMachina1->GetVehicleCount(); ++k)
	{
		Vehicle* tmp = deusExMachina1->GetVehicle(k);
		printf("Vehicle[%d] Added: %16p [%s]\n", k, tmp, typeid(*tmp).name());
	}
	
	printf("\n");
	*/

	deusExMachina1->Travel(); // 01 // 모든 운송 수단이 이동
	deusExMachina1->Travel(); // 02 // Boat, Motorcycle, 두 Sedan, UBoat 가 이동
	deusExMachina1->Travel(); // 03 // Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // 04 // Boat, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // 05 // UBoat 만 빼고 전부 이동
	deusExMachina1->Travel(); // 06 // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // 07 // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat 가 이동
	deusExMachina1->Travel(); // 08 // Boat, Motorcycle, 두 Sedan, UBoat 가 이동
	deusExMachina1->Travel(); // 09 // Airplane, Boatplane, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // 10 // Boat, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // 11 // Boat, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // 12 // 트레일러 달린 Sedan 만 이동
	deusExMachina1->Travel(); // 13
	/*
	printf("\n");

	for (unsigned int k = 0; k < deusExMachina1->GetVehicleCount(); ++k)
	{
		Vehicle* tmp = deusExMachina1->GetVehicle(k);
		printf("Vehicle[%d] Added: %16p [%s], Position: %d, MaxSpeed: %d\n", k, tmp, typeid(*tmp).name(), tmp->GetPosition(), tmp->GetMaxSpeed());
	}
	*/
	assert(deusExMachina1->GetFurthestTravelled() == boat);

	return 0;
}