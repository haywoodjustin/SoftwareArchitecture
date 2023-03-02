#include "RoutingFeature.h"
#include "Wire.h"



void ProcessRoutingFeature(std::string featureType, std::ifstream& streamObject)
{

	if (featureType == "Wire")
	{
		ReadInWire(streamObject);
	}


}
