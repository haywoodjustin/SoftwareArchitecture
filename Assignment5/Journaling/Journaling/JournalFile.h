#pragma once
#include <sstream>
#include "JournalingTypes.h"
namespace Journal
{
	class JournalFile
	{
	public:
		JournalFile(std::string fileName, JournalingLanguage jnlLang);

		virtual ~JournalFile();

		void WriteJournalFile();

		void WriteToFile(std::string& lineToWrite);
		void NewLine();

	private:
		void ProFormaStart();
		void ProFormaStartCPP();
		void ProFormaStartJava();
		void ProFormEnd();
		void ProFormEndCPP();
		void ProFormEndJava();

		std::stringstream m_journalContents;
		std::string m_journalFileName;
		std::ofstream* m_file;
		std::stringstream preProForma; // Include files for example
		JournalingLanguage m_jnlLang;
	};
}

