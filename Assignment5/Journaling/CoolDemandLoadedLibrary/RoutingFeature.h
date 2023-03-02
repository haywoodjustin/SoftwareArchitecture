#pragma once

#include "CoolDemandLoadedLibraryExports.h"
#include <iostream>
#include <fstream>

static std::string RoutingFeatureToken = "RoutingFeature:";
static std::string EndRoutingFeatureToken = "EndRoutingFeature";


void ProcessRoutingFeature(std::string featureType, std::ifstream& streamObject);

class COOLDEMANDLOADEDLIBRARY_API RoutingFeature
{
};
