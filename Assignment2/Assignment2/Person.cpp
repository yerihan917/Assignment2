#include "Person.h" 

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
	{
		m_name = name;
		m_weight = weight;
	}

	Person::~Person()
	{
	}

	const std::string& Person::GetName() const
	{
		return m_name;
	}

	unsigned int Person::GetWeight() const
	{
		return m_weight;
	}
}
