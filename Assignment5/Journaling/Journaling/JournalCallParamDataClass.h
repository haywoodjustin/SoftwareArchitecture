#pragma once
#include <string>
#include "JournalCallParamData.h"

class GuidObject;
namespace Journal
{
	class JournalCallParamDataClass : public JournalCallParamData
	{
	public:


		JournalCallParamDataClass(std::string paramName,
			ParameterMetaType paramType, GuidObject* classObject, std::string className);

		void Journal() override;
		JournalCallParamDataClass() = delete;
		JournalCallParamDataClass(const JournalCallParamDataClass&) = delete;
		JournalCallParamDataClass& operator=(const JournalCallParamDataClass&) = delete;
	private:

		GuidObject* m_classObject;
		std::string m_paramName;
		std::string m_className;
	};

}
