#pragma once 

namespace assignment2
{
	// 도로 주행
	class IDrivable
	{
	public:
		virtual unsigned int GetDriveSpeed() = 0;
	};
}
