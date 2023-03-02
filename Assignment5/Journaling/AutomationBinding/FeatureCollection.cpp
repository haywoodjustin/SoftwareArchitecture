#include "AutomationAPI_FeatureCollection.h"
#include "AutomationAPI_Block.h"
#include "AutomationAPI_BlockBuilder.h"
#include <iostream>
#include "..\AppLibrary\Journaling_FeatureCollection.h"
#include "..\AppLibrary\Block.h"
#include "..\AppLibrary\BlockBuilder.h"
#include "..\AppPartOps\PartOps.h"

AutomationAPI::FeatureCollection::FeatureCollection(int guid) : m_guid(guid)
{

}

AutomationAPI::FeatureCollection::~FeatureCollection()
{

}

AutomationAPI::BlockBuilder* AutomationAPI::FeatureCollection::CreateBlockBuilder(AutomationAPI::Block* block)
{
	int guid = 0;
	Application::Block* appBlock = nullptr;
	if (block != nullptr)
	{
		guid = block->GetGuid();
		appBlock = new Application::Block(guid);
	} 

	Application::PartFile* part = 
		dynamic_cast<Application::PartFile*>(
			GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(m_guid));
	if (part == nullptr)
	{
		throw std::exception("not able to retrieve Part Object");
	}

	Application::BlockBuilder * blockBuilder =
		Journaling_FeatureCollection_CreateBlockBuilder(part, appBlock);

	int guidBlockBuilder = blockBuilder->GetGuid();

	return AutomationAPI::BlockBuilder::CreateBlockBuilder(guidBlockBuilder);

}
