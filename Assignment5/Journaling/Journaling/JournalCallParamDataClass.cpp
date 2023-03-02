#include "JournalCallParamDataClass.h"
#include "JournalingInternal.h"
#include "JournalFile.h"
#include "..\Core\GuidObject.h"

using namespace Journal;

JournalCallParamDataClass::JournalCallParamDataClass(std::string paramName, ParameterMetaType paramType,
    GuidObject* classObject, std::string className) :
    JournalCallParamData(paramName, paramType, JournalCallParamData::ParameterBasicType::STRING), m_classObject(classObject),
    m_paramName(paramName), m_className(className)
{

}

void JournalCallParamDataClass::Journal()
{


    if (this->m_paramType == JournalCallParamData::ParameterMetaType::INPUT)
    {
        //TODO only handled the nullptr case
        if (this->m_classObject == nullptr)
        {
            std::string jnlString = "nullptr";
            GetActiveJournalFile()->WriteToFile(jnlString);
        }
        else
        {
            throw std::exception("NIY ");
        }
    }
    else if (this->m_paramType == JournalCallParamData::ParameterMetaType::OUTPUT)
    {
        throw std::exception("NIY ");
    }
    else // RETURN
    {
        std::string paramName;

        if (!InGuidToParamMap(this->m_classObject->GetGuid()))
        {
            paramName = GenerateVariableName(m_paramName);
            AddGuidToParamMap(this->m_classObject->GetGuid(), paramName);

            std::string jnlString = m_className + " * " + paramName + " = ";
            GetActiveJournalFile()->WriteToFile(jnlString);
        }
        else
        {
            bool found = false;
            paramName = GetGuidToParam(this->m_classObject->GetGuid(), found);
            //from a query method called multiple times
            std::string jnlString ;
            if (found)
            {
                jnlString = paramName + " = ";
            }
            else
            {
                std::string temp = "<UNKNOWN>";
                jnlString = temp + " = ";
            }
            GetActiveJournalFile()->WriteToFile(jnlString);

        }




    }

}