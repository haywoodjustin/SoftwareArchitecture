#pragma once
#include "CoreExports.h"

class CORE_API GuidObject
{
	public :
		GuidObject(int guid);
		

		int GetGuid();


		virtual ~GuidObject();
		GuidObject() = delete;
	protected:
		
		int m_guid;

};

class CORE_API GuidObjectManager
{
	public:
		static GuidObjectManager& GetGuidObjectManager();

		GuidObject* GetObjectFromGUID(int guid);
		void SetObjectFromGUID(int guid, GuidObject* objectToStore);
		GuidObjectManager(const GuidObjectManager&) = delete;
		GuidObjectManager& operator=(const GuidObjectManager&) = delete;

	private:
		GuidObjectManager() = default;
		~GuidObjectManager() = default;


};

