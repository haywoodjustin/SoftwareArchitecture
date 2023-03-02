#include "PartOps.h"
#include "PartOpsInternal.h"
#include "DelMeBadPattern.h"
#include <iostream>
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"
#include "..\Core\GuidObject.h"
#include "..\AppLibrary\Feature.h"
#include "..\Core\StringUtils.h"
#include "..\Core\CoreSession.h"
#include "..\Core\Observer.h"

using namespace std;


Application::PartFile::PartFile(std::string partFilePath, int guid) : GuidObject(guid),  m_partFilePath(partFilePath)
{
	cout << "    PartFile::PartFile called with " << partFilePath << " " << guid << endl;
}

void Application::PartFile::ClosePart()
{
	cout << "    PartFile::ClosePart called" << endl;

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = this->GetGuid();
	partOpsNotifierData.partName = this->m_partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::ClosePart, (void*)ptr);
}

void Application::PartFile::SavePart()
{
	cout << "    PartFile::SavePart called" << endl;

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = this->GetGuid();
	partOpsNotifierData.partName = this->m_partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::SavePart, (void*)ptr);
}

void Application::PartFile::MakeWidgetFeature(bool option1, int values)
{
	cout << "    MakeWidgetFeature called with " << option1 << " " << values << endl;
}

Application::PartFile* Application::PartFile::CreatePartFile(std::string partFilePath)
{
	int guid = 123424; 

	Application::PartFile* partFile = new Application::PartFile( partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);

	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = guid;
	partOpsNotifierData.partName = partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::CreatePart, (void*)ptr);
	return partFile;
}

Application::PartFile* Application::PartFile::OpenPartFile(std::string partFilePath)
{
	int guid = -1;
	
	ReadInPartFile(guid, partFilePath);


	PartFile* partFile = new PartFile(partFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, partFile);
	
	PartOpsNotifierData partOpsNotifierData;
	partOpsNotifierData.guid = guid;
	partOpsNotifierData.partName = partFilePath;
	PartOpsNotifierData* ptr = &partOpsNotifierData;

	CoreSession::GetInstance().CreateMessage(Observer::OpenPart, (void*)ptr);

	return partFile;
}



std::string PartFileNameToken = "PartFileName:";
std::string SchemaVersionToken = "SchemaVersion:";



void ReadInPartFile(int & guid, std::string partFilePath)
{
	guid = 54321;
	string line;
	ifstream localPartFile(partFilePath);
	if (localPartFile.is_open())
	{
		while (getline(localPartFile, line))
		{
			cout << line << '\n';

			if (startsWith(line, PartFileNameToken))
			{
				std::string partFileName = line.substr(PartFileNameToken.size(), line.size() - PartFileNameToken.size());
				cout << "    "<< PartFileNameToken << " " << partFileName << endl;
			}
			else if (startsWith(line, SchemaVersionToken))
			{
				std::string partFileName = line.substr(SchemaVersionToken.size(), line.size() - SchemaVersionToken.size());
				cout << "    "<< SchemaVersionToken <<" " << partFileName << endl;
			}
			else if(startsWith(line, FeatureToken))
			{
				std::string featureType = line.substr(FeatureToken.size(), line.size() - FeatureToken.size());
				ProcessFeature(featureType, localPartFile);
			}


		}
		localPartFile.close();
	}


}













