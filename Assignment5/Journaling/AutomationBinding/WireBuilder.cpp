#include "AutomationAPI_WireBuilder.h"
#include "AutomationAPI_CADObject.h"



AutomationAPI::CADObject* AutomationAPI::WireBuilder::Commit()
{
	return nullptr;
}

void AutomationAPI::WireBuilder::SetType(AutomationAPI::WireBuilder::WireBuilderTypes type)
{
}

AutomationAPI::WireBuilder::WireBuilderTypes AutomationAPI::WireBuilder::GetType()
{
	return AutomationAPI::WireBuilder::TypesOption1;
}



void AutomationAPI::WireBuilder::SetOrigin1(int x, int y, int z)
{
}

void AutomationAPI::WireBuilder::GetOrigin1(int& x, int& y, int& z)
{
}

void AutomationAPI::WireBuilder::SetOrigin2(int x, int y, int z)
{
}

void AutomationAPI::WireBuilder::GetOrigin2(int& x, int& y, int& z)
{
}
