#pragma once

#include <string>
#include "JournalCallParamData.h"

namespace Journal
{
	class JournalCallParamDataString : public JournalCallParamData
	{
	public:


		JournalCallParamDataString(std::string paramName,
			ParameterMetaType paramType, std::string value);

		void Journal() override;
		JournalCallParamDataString() = delete;
		JournalCallParamDataString(const JournalCallParamDataString&) = delete;
		JournalCallParamDataString& operator=(const JournalCallParamDataString&) = delete;
	private:

		std::string m_value;
	};

}