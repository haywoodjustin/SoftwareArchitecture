#include "WireVersions.h"


Wire2::Wire2(std::string distance, int guid)
	: IWire(guid), m_distance(distance)
{

}

std::string Wire2::GetVersion()
{
	return "2";
}