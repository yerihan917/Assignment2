#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
	{
		m_weight = weight;
	}

	Trailer::~Trailer()
	{

	}

	unsigned int Trailer::GetWeight() const
	{
		return m_weight;
	}
}
