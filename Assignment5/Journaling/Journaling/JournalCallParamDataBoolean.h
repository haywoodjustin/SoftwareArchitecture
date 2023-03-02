#pragma once
#include <string>
#include "JournalCallParamData.h"

namespace Journal
{
	class JournalCallParamDataBoolean : public JournalCallParamData
	{
	public:
		JournalCallParamDataBoolean(std::string paramName,
			ParameterMetaType paramType, bool value);

		void Journal() override;
		JournalCallParamDataBoolean() = delete;
		JournalCallParamDataBoolean(const JournalCallParamDataBoolean&) = delete;
		JournalCallParamDataBoolean& operator=(const JournalCallParamDataBoolean&) = delete;
	private:

		int m_value;
	};
}
