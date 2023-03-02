#include "JournalCallParamDataInteger.h"
#include "JournalingInternal.h"
#include "JournalFile.h"

using namespace Journal;

JournalCallParamDataInteger::JournalCallParamDataInteger(std::string paramName,
    ParameterMetaType paramType, int value) :
    JournalCallParamData(paramName, paramType,
        JournalCallParamData::ParameterBasicType::INTEGER), m_value(value)
{

}

void JournalCallParamDataInteger::Journal()
{
    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {
        //TODO
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw std::exception("NIY ");
    }
    else // RETURN
    {
        throw std::exception("NIY");
    }


}