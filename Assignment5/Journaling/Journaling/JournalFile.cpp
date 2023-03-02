#include "JournalFile.h"
#include "JournalingTypes.h"
#include <fstream>

using namespace Journal;

JournalFile::JournalFile(std::string fileName, JournalingLanguage jnlLang)
	: m_journalFileName(fileName), m_jnlLang(jnlLang), m_journalContents(), m_file(new std::ofstream(fileName))
{
	 
}

void JournalFile::WriteJournalFile()
{
	ProFormaStart();
	*m_file << m_journalContents.str() << std::endl;
	ProFormEnd();
	m_file->close();
}

JournalFile::~JournalFile()
{
    if (m_file != nullptr)
    {
        m_file->close();
    }
	delete m_file;
}

void JournalFile::NewLine()
{
    m_journalContents << std::endl;
}

void JournalFile::WriteToFile(std::string& contentToWrite)
{
    m_journalContents << contentToWrite;
}

void JournalFile::ProFormEnd()
{
    if (m_jnlLang == JournalingLanguage::CPP)
    {
        ProFormEndCPP();
    }
    else
    {
        ProFormEndJava();
    }
}

void JournalFile::ProFormEndCPP()
{
    *m_file << "}" << std::endl;
}
void JournalFile::ProFormEndJava()
{
    *m_file << "NIY END" << std::endl;
}

void JournalFile::ProFormaStart()
{
    if (m_jnlLang == JournalingLanguage::CPP)
    {
        ProFormaStartCPP();
    }
    else
    {
        ProFormaStartJava();
    }
}

void JournalFile::ProFormaStartCPP()
{
    //Write out include Files
    *m_file << "#include <iostream>" << std::endl;
    *m_file << "#include \"..\\AutomationBinding\\AutomationAPI_Session.h\"" << std::endl;
    *m_file << "#include \"..\\AutomationBinding\\AutomationAPI_Part.h\"" << std::endl;

    *m_file << preProForma.str() << std::endl;

    *m_file << "int main()" << std::endl;
    *m_file << "{" << std::endl;
    *m_file << "    std::cout << \"Hello World!\\n\";" << std::endl;
    *m_file << "    AutomationAPI::Session* mySession = AutomationAPI::Session::GetSession();" << std::endl;
}

void JournalFile::ProFormaStartJava()
{
    *m_file << "NIY Java" << std::endl;
}
