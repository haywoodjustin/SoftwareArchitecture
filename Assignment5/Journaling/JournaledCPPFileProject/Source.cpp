#include <iostream>
#include "..\AutomationBinding\AutomationAPI_Session.h"
#include "..\AutomationBinding\AutomationAPI_Part.h"


int NotMain()
{
    std::cout << "Hello World!\n";

    AutomationAPI::Session* mySession = AutomationAPI::Session::GetSession();

    AutomationAPI::Part* myPart = mySession->MakePart("d:\\workdir\\someDir\\SomeName.part");
    myPart->MakeWidgetFeature(true, 10);
    myPart->Save();


    delete myPart;

    return 0;
}