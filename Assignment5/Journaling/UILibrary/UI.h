#pragma once

#include "UILIbraryExports.h"
#include "..\Core\Observer.h"


class UILIBRARY_API UI
{
public:

	UI();

	void Init();

	void StartGUILoop();

	void ShutDownGUILoop();

private:
	void PerformSampleJournalingPartsOps();
	void PerformPartsOpsThatNeedsToLoadDemandLoadedLibrary();
	void PerformJavaAutomationWorkflow();
	void PerformDotnetAutomationWorkflow();
	void PerformSampleUsingBuilder();

	Observer* observer4;
	Observer* observer5;

};