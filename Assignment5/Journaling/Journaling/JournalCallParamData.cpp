#include "JournalCallParamData.h"
using namespace Journal;

JournalCallParamData::JournalCallParamData(std::string paramName,
    ParameterMetaType paramType, ParameterBasicType parameterBasicType) :
    m_paramName(paramName), m_paramType(paramType), m_parameterBasicType(parameterBasicType),
    m_isClass(false), m_className()
{

}

JournalCallParamData::JournalCallParamData(std::string paramName, ParameterMetaType paramType,
    std::string className) : m_paramName(paramName), m_paramType(paramType),
    m_isClass(true), m_className(className), m_parameterBasicType(ParameterBasicType::NOT_BASIC)
{

}