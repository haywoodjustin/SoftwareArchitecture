#include "JournalCallData.h"
#include "JournalingInternal.h"
#include "JournalFile.h"
#include "JournalCallParamData.h"
#include "..\Core\GuidObject.h"

using namespace Journal;

JournalCallData::JournalCallData(std::string methodName, CannedGlobals cannedGlobals)
    : m_methodName(methodName), m_cannedGlobal(cannedGlobals), m_isCanned(true), m_retVal(nullptr), m_classObject(nullptr)
{
}

JournalCallData::JournalCallData(std::string methodName, GuidObject* m_classObject)
    : m_methodName(methodName), m_cannedGlobal(CannedGlobals::NOT_CANNED), m_isCanned(false), m_retVal(nullptr), m_classObject(m_classObject)
{

}

void JournalCallData::AddParameter(JournalCallParamData* param)
{
    m_params.push_back(param);
}

void JournalCallData::AddReturnValue(JournalCallParamData* param)
{
    m_retVal = param;
}

JournalCallData::~JournalCallData()
{
    for (int i = 0; i < m_params.size(); i++)
    {
        delete m_params[i];
    }

    delete m_retVal;
}

void JournalCallData::Journal()
{
    // First check if we have a return value
    if (this->m_retVal != nullptr)
    {
        m_retVal->Journal();
    }
    // Then print out call to object (the this) and the method call

    if (this->m_isCanned)
    {
        if (this->m_cannedGlobal == CannedGlobals::SESSION)
        {
            std::string jnlString = "mySession->";
            GetActiveJournalFile()->WriteToFile(jnlString);
        }
    }
    else
    {
        bool found = false;
        //Retrieve param Name
        std::string paramName = GetGuidToParam(this->m_classObject->GetGuid(), found);
        std::string jnlString;
        if (found)
        {
            jnlString = paramName + "->";
        }
        else
        {
            std::string temp = "<UNKNOWN>";
            jnlString = temp + "->";
        }

        GetActiveJournalFile()->WriteToFile(jnlString);
    }

    static std::string beginParam = std::string("(");

    std::string jnlString = this->m_methodName + beginParam;

    GetActiveJournalFile()->WriteToFile(jnlString);
    static std::string commaString = std::string(",");
    for (int i = 0; i < m_params.size(); i++)
    {    
        //If more than 1 parameter, put in comma
        if (i > 0)
        {
            GetActiveJournalFile()->WriteToFile(commaString);
        }
        m_params[i]->Journal();

    }

    static std::string endParam = std::string(");");
    GetActiveJournalFile()->WriteToFile(endParam);
    GetActiveJournalFile()->NewLine();

}
