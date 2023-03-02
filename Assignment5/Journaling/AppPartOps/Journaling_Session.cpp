#include "Journaling_Session.h"
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"

Application::PartFile* Journaling_Session_OpenPart(std::string partFilePath)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("OpenPart", CannedGlobals::SESSION);
		JournalStringInParam(partFilePath, "partFilePath");
	}
	Application::PartFile* retVal = nullptr;
	retVal = Application::PartFile::OpenPartFile(partFilePath);

	if (IsJournaling())
	{
		JournalReturnClass(retVal, "AutomationAPI::Part", "Part");
		JournalEndCall();
	}

	return retVal;

}

Application::PartFile* Journaling_Session_MakePart(std::string partFilePath)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("MakePart", CannedGlobals::SESSION);
		JournalStringInParam(partFilePath, "partFilePath");
	}
	Application::PartFile* retVal = nullptr;
	retVal = Application::PartFile::CreatePartFile(partFilePath);

	if (IsJournaling())
	{
		JournalReturnClass(retVal, "AutomationAPI::Part", "Part");
		JournalEndCall();
	}

	return retVal;

}
