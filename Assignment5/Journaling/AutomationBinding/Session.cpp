#include "AutomationAPI_Session.h"
#include "AutomationAPI_Part.h"
#include "..\Core\Core.h"
#include "..\AppPartOps\PartOps.h"
#include "..\AppPartOps\Journaling_Session.h"


AutomationAPI::Session* AutomationAPI::Session::GetSession()
{
	static Session instance;
	bool authorized = true;

	if (!authorized || initializeProduct() != 0)
	{
		throw std::exception("Not authorized to get Session, purchase license");
	}

	return &instance;
	
}

AutomationAPI::Part* AutomationAPI::Session::MakePart(std::string partFilePath)
{
	Application::PartFile * partFile =  Journaling_Session_MakePart(partFilePath);

	int guid = partFile->GetGuid();

	return AutomationAPI::Part::CreatePart(guid);
}

AutomationAPI::Part* AutomationAPI::Session::OpenPart(std::string partFilePath)
{
	Application::PartFile* partFile = Journaling_Session_OpenPart(partFilePath);

	int guid = partFile->GetGuid();

	return AutomationAPI::Part::CreatePart(guid);
}


AutomationAPI::Session::~Session()
{
	shutdownProduct();
}

