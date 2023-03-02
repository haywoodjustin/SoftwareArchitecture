#pragma once

#include "Wire.h"
#include <string>

class Wire2 : public RoutingFeature, public IWire
{
public:
	Wire2(std::string distance, int guid);
	std::string GetVersion() override;

	const std::string& GetDistance()
	{
		return m_distance;
	};



private:
	std::string m_distance;

};

