#pragma once
#include "CoolDemandLoadedLibraryExports.h"
#include "RoutingFeature.h"
#include <iostream>
#include <fstream>
#include "..\Core\GuidObject.h"


void ReadInWire(std::ifstream& streamObject);

class COOLDEMANDLOADEDLIBRARY_API IWire : public GuidObject
{
public:
	virtual std::string GetVersion() = 0;
	IWire() = delete;
	IWire(int guid) : GuidObject(guid)
	{

	}

};

class COOLDEMANDLOADEDLIBRARY_API Wire : public RoutingFeature, public IWire
{
public:
	Wire(std::string distance, int guid);
	std::string GetVersion() override;

	const std::string& GetDistance()
	{
		return m_distance;
	};


private:
	std::string m_distance;

};




