#pragma once

#include <string>
#include <vector>
#include "JournalingTypes.h"

class GuidObject;


namespace Journal
{
	class JournalCallParamData;

	/// <summary>
	/// This represent the data needed to journal a method call
	/// </summary>
	class JournalCallData
	{
	public:
		/// <summary>
		/// Constructor for CallData
		/// </summary>
		/// <param name="methodName">The Method Name</param>
		/// <param name="cannedGlobals">If this is being made upon a CannedGlobal</param>
		JournalCallData(std::string methodName, CannedGlobals cannedGlobals);
		/// <summary>
		/// Constructor for CallData based upon a class
		/// </summary>
		/// <param name="methodName">The Method Name</param>
		/// <param name="classObject">Class GUID</param>
		JournalCallData(std::string methodName, GuidObject* classObject);
		void AddParameter(JournalCallParamData* param);
		void AddReturnValue(JournalCallParamData* param);

		virtual ~JournalCallData();

		void Journal();
		JournalCallData() = delete;
		JournalCallData(const JournalCallData&) = delete;
		JournalCallData& operator=(const JournalCallData&) = delete;
	private:

		std::string m_methodName;
		std::vector<JournalCallParamData*> m_params;
		bool m_isCanned;
		GuidObject* m_classObject;
		CannedGlobals m_cannedGlobal;
		JournalCallParamData* m_retVal; // nulptr is void

	};
}


