#include <iostream>
#include "..\AutomationBinding\AutomationAPI_Session.h"
#include "..\AutomationBinding\AutomationAPI_Part.h"

int main()
{
    std::cout << "Hello World!\n";
    AutomationAPI::Session* mySession = AutomationAPI::Session::GetSession();
AutomationAPI::Part * Part1 = mySession->MakePart("d:\\workdir\\someDir\\SomeName.part");
Part1->MakeWidgetFeature(true,10);
Part1->Save();
AutomationAPI::Part * Part2 = mySession->OpenPart("C:\\Users\\polek\\source\\repos\\AutomationAPI_pt2\\SampleVersionUp.prt");
Part2->Save();
}
