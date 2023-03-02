#pragma once

#include <string>
#include "JournalCallParamData.h"

namespace Journal
{
	class JournalCallParamDataInteger : public JournalCallParamData
	{
	public:
		JournalCallParamDataInteger(std::string paramName,
			ParameterMetaType paramType, int value);

		void Journal() override;
		JournalCallParamDataInteger() = delete;
		JournalCallParamDataInteger(const JournalCallParamDataInteger&) = delete;
		JournalCallParamDataInteger& operator=(const JournalCallParamDataInteger&) = delete;
	private:

		int m_value;

	};
}
