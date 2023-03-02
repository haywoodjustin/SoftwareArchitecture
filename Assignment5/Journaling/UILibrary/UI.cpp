
#include "UI.h"
#include "..\PartOpsUI\PartsUtilsUI.h"
#include "..\FeatureOpsUI\MakeWidgetFeature.h"
#include "..\AppPartOps\PartOps.h"
#include "..\Journaling\Journaling.h"
#include "..\Core\LibraryLoad.h"
#include "..\Core\CoreSession.h"
#include "..\Core\Observer.h"
#include "..\JavaLoader\JavaLoader.h"
#include "..\Core\CoreUtils.h"
#include "..\FeatureOpsUI\BlockBuilderUI.h"
#include "..\AppLibrary\Journaling_BlockBuilder.h"

UI::UI()
{

}

void UI::Init()
{
	CoreSession::GetInstance().SetupDefaultObservers();

	CoreSession::GetInstance().CreateMessage("Hello World! :D");
	CoreSession::GetInstance().CreateMessage("The weather is hot today! :p");
	observer4 = new Observer(CoreSession::GetInstance(), Observer::ClosePart);
	observer5 = new Observer(CoreSession::GetInstance(), Observer::SavePart);
	CoreSession::GetInstance().CreateMessage("My new car is great! ;)");

}

// To mimic differetn workflows, and User interactions, I have pre-planned scripts to have run.  
// It should be legal to run all of these scenarios, but the idea is we pick on scenario to run
// and hardcode it and then that mimics the user workflow used

// Option 1
// In this we start journaling a file, open a part, add a widget to the part, save the part,
// and then open another part and then save that part.

// Option 2
// Is we run some a Java Automation program from inside of our cad Application

// Option3 
// Is we run a .Net automation program from inside our cad Application



void UI::StartGUILoop()
{
	int WorkFlowToRun = 1;

	if (WorkFlowToRun == 1)
	{
		PerformSampleJournalingPartsOps();
	}
	else if (WorkFlowToRun == 2)
	{
		PerformPartsOpsThatNeedsToLoadDemandLoadedLibrary();
	}
	else if (WorkFlowToRun == 3)
	{
		PerformJavaAutomationWorkflow();
	}
	else if (WorkFlowToRun == 4)
	{
		PerformDotnetAutomationWorkflow();
	}
	else if (WorkFlowToRun == 5)
	{
		PerformSampleUsingBuilder();
	}
	else
	{
		std::cout << "Unknown Workflow\n" << std::endl;
	}

}

void UI::ShutDownGUILoop()
{
	observer4->RemoveMeFromTheList();
	observer5->RemoveMeFromTheList();

}

void UI::PerformPartsOpsThatNeedsToLoadDemandLoadedLibrary()
{
	//TODO this needs work to show usage of the deman loaded library

	// This is just mimic'ing a simple CAD workflow.
	// We are going to pretend the user makes  part, makes a widget feature, saves the part,
	// and then exits.  And this will stop the GUI loop and lead to exit on main

	//Setup Journaling File
	SetJournalingLangauge(JournalingLanguage::CPP);
	StartJournaling(BasePath() + "\\JournaledCPPFileProject\\SampleJournal.txt");


	Application::PartFile* partFile = MakePartUI("d:\\workdir\\someDir\\SomeName.part");
	AddWidgetFeatureToPartUI(partFile, true, 10);
	SavePartUI(partFile);

	Application::PartFile* partFile2 = OpenPartUI(BasePath() + "\\SampleVersionUp.prt");

	SavePartUI(partFile2);

	//End Journaling
	EndJournaling();

	std::cout << "Before Loaded Library" << std::endl;
	HINSTANCE handle = CoreLoadLibrary("COOLDEMANDLOADEDLIBRARY.dll");
	std::cout << "After Loaded Library" << std::endl;
	UnloadLibrary(handle);
	std::cout << "After UnLoaded Library" << std::endl;
}

void UI::PerformSampleJournalingPartsOps()
{
	// This is just mimic'ing a simple CAD workflow.
	// We are going to pretend the user makes  part, makes a widget feature, saves the part,
	// and then exits.  And this will stop the GUI loop and lead to exit on main

	//Setup Journaling File
	SetJournalingLangauge(JournalingLanguage::CPP);
	StartJournaling(BasePath() +"\\JournaledCPPFileProject\\SampleJournal.txt");


	Application::PartFile* partFile = MakePartUI("d:\\workdir\\someDir\\SomeName.part");
	AddWidgetFeatureToPartUI(partFile, true, 10);
	SavePartUI(partFile);

	Application::PartFile* partFile2 = OpenPartUI(BasePath() + "\\SampleVersionUp.prt");

	SavePartUI(partFile2);

	//End Journaling
	EndJournaling();
}

void UI::PerformSampleUsingBuilder()
{
	// This is just mimic'ing a simple CAD workflow.
	// We are going to pretend the user makes  part, makes a widget feature, saves the part,
	// and then exits.  And this will stop the GUI loop and lead to exit on main

	//Setup Journaling File
	SetJournalingLangauge(JournalingLanguage::CPP);
	StartJournaling(BasePath() + "\\JournaledCPPFileProject\\SampleJournal.txt");


	Application::PartFile* partFile = MakePartUI("d:\\workdir\\someDir\\SomeName.part");
	
	Application::BlockBuilder* blockBuilder = CreateBlockBuilderUI(partFile, nullptr);
	Journaling_BlockBuilder_SetType(blockBuilder, JournalBlockBuilderTypes::JournalTypesDiagonalPoints);
	
	SavePartUI(partFile);

	//End Journaling
	EndJournaling();



}


void UI::PerformJavaAutomationWorkflow()
{
// To resolve build errors and you don't want to setup the java portion just chagne the #ifdef value to be zero
#if 1
	CreateJVM();

	std::string baseString = BasePath();
	std::cout << "baseString " << baseString << std::endl;
	//RunJavaProgram1("FirstProgram");
	RunJavaProgramWithClassLoader(BasePath() + "\\SimpleHelloWorldJava\\HelloWorld.class");

	RunJavaProgramWithClassLoader(BasePath() + "\\FakeAutomationJava\\CallFakeJavaAutomation.class");
	DestroyJVM();

#endif
}

void UI::PerformDotnetAutomationWorkflow()
{
}
