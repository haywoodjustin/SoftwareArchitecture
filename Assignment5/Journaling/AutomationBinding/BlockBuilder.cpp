#include "AutomationAPI_BlockBuilder.h"
#include "AutomationAPI_CADObject.h"
#include "..\AppLibrary\Journaling_BlockBuilder.h"
#include <exception>

namespace AutomationAPI
{
	class BlockBuilderImpl
	{
	public:

		virtual ~BlockBuilderImpl();
		BlockBuilderImpl() = delete;

		BlockBuilderImpl(int guid);
		int m_guid;

	};
}

AutomationAPI::BlockBuilder::BlockBuilder(int guid)
{
	m_blockBuilderImpl = new AutomationAPI::BlockBuilderImpl(guid);
}

AutomationAPI::BlockBuilder::~BlockBuilder()
{
	delete m_blockBuilderImpl;
}

AutomationAPI::BlockBuilderImpl::BlockBuilderImpl(int guid)
{
	m_guid = guid;
}

AutomationAPI::BlockBuilderImpl::~BlockBuilderImpl()
{

}


AutomationAPI::BlockBuilder* AutomationAPI::BlockBuilder::CreateBlockBuilder(int guid)
{
	// We should check the guid being passed in, as this is public
	// but that is for another day

	return new AutomationAPI::BlockBuilder(guid);
}

AutomationAPI::CADObject* AutomationAPI::BlockBuilder::Commit()
{
	return nullptr;
}

void AutomationAPI::BlockBuilder::SetType(AutomationAPI::BlockBuilder::BlockBuilderTypes type)
{
	Application::BlockBuilder* blockBuilder =
		dynamic_cast<Application::BlockBuilder*>(
			GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(m_blockBuilderImpl->m_guid));
	if (blockBuilder == nullptr)
	{
		throw std::exception("not able to retrieve blockBuilder Object");
	}

	Journaling_BlockBuilder_SetType(blockBuilder,(JournalBlockBuilderTypes) type);

}

AutomationAPI::BlockBuilder::BlockBuilderTypes AutomationAPI::BlockBuilder::GetType()
{
	Application::BlockBuilder* blockBuilder =
		dynamic_cast<Application::BlockBuilder*>(
			GuidObjectManager::GetGuidObjectManager().GetObjectFromGUID(m_blockBuilderImpl->m_guid));

	if (blockBuilder == nullptr)
	{
		throw std::exception("not able to retrieve blockBuilder Object");
	}

	
	int t = (int)Journaling_BlockBuilder_GetType(blockBuilder);
	AutomationAPI::BlockBuilder::BlockBuilderTypes type = (AutomationAPI::BlockBuilder::BlockBuilderTypes)t;

	return type;
}

void AutomationAPI::BlockBuilder::SetHeight(int h)
{
}

int AutomationAPI::BlockBuilder::GetHeight()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetWidth(int w)
{
}

int AutomationAPI::BlockBuilder::GetWidth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetDepth(int d)
{
}

int AutomationAPI::BlockBuilder::GetDepth()
{
	return 0;
}

void AutomationAPI::BlockBuilder::SetOrigin(int x, int y, int z)
{
}

void AutomationAPI::BlockBuilder::GetOrigin(int& x, int& y, int& z)
{
}
