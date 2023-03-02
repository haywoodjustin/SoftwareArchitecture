#include "PartsUtilsUI.h"
#include <iostream>
#include "..\AppPartOps\PartOps.h"
#include "..\AppPartOps\Journaling_Session.h"
#include "..\AppPartOps\Journaling_Part.h"

void SavePartUI(Application::PartFile* partFile)
{
	std::cout << "SavePartUI was called" << std::endl;
	
	Journaling_Part_Save(partFile);
	
}

Application::PartFile* MakePartUI(std::string s)
{
	std::cout << "MakePartUI was called with args " << s << std::endl;

	return Journaling_Session_MakePart(s);
}

Application::PartFile* OpenPartUI(std::string s)
{
	std::cout << "OpenPartUI was called with args " << s << std::endl;

	return Journaling_Session_OpenPart(s);

}

