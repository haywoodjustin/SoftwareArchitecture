#pragma once

#include <string>
namespace Journal
{
	class JournalCallParamData
	{
	public:
		enum class ParameterMetaType
		{
			INPUT,
			OUTPUT,
			RETURN
		};

		enum class ParameterBasicType
		{
			STRING,
			BOOLEAN,
			INTEGER,
			NOT_BASIC
		};

		virtual void Journal() = 0;
		JournalCallParamData() = delete;
		JournalCallParamData(const JournalCallParamData&) = delete;
		JournalCallParamData& operator=(const JournalCallParamData&) = delete;
	protected:
		JournalCallParamData(std::string paramName,
			ParameterMetaType paramType, ParameterBasicType parameterBasicType);
		JournalCallParamData(std::string paramName, ParameterMetaType paramType,
			std::string className);


		std::string m_paramName;
		ParameterMetaType m_paramType;
		bool m_isClass;
		ParameterBasicType m_parameterBasicType;
		std::string m_className;


	};
}
