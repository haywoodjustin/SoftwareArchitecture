#include "GuidObject.h"
#include <map>
GuidObject::GuidObject(int guid) : m_guid(guid)
{

}


GuidObject::~GuidObject()
{

}

int GuidObject::GetGuid()
{
	return m_guid;
}

std::map<int, GuidObject*> m_guidToObjectMap ;

GuidObjectManager& GuidObjectManager::GetGuidObjectManager()
{
	static GuidObjectManager instance;
	return instance;
}

GuidObject* GuidObjectManager::GetObjectFromGUID(int guid)
{
	return m_guidToObjectMap[guid];
}

void GuidObjectManager::SetObjectFromGUID(int guid, GuidObject* objectToStore)
{
	m_guidToObjectMap[guid] = objectToStore;
}
