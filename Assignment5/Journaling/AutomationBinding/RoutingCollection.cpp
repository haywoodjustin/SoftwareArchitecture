#include "AutomationAPI_RoutingCollection.h"
#include "AutomationAPI_Wire.h"
#include "AutomationAPI_WireBuilder.h"
#include <iostream>

AutomationAPI::RoutingCollection::RoutingCollection(int guid) : m_guid(guid)
{

}

AutomationAPI::RoutingCollection::~RoutingCollection()
{

}

AutomationAPI::WireBuilder* AutomationAPI::RoutingCollection::CreateWireBuilder(AutomationAPI::Wire* wire)
{
	if (wire == nullptr)
	{
		std::cout << "Block is creation mode" << std::endl;
	}
	else
	{
		std::cout << "Block is edit/query mode" << std::endl;
	}


	return nullptr;

}
