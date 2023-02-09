#pragma once

#include "UserInterfaceExports.h"
#include "../BlobLibrary/MyApplication1.h"
#include "../BlobLibrary/MyApplication2.h"


/// <summary>
/// This class has the UI functionality for our Application
/// </summary>
class USERINTERFACE_API UI
{
public:

	UI();


	void Init();

	void StartGUILoop();

private:
	MyApplication1* m_application1;
	MyApplication2* m_application2; 
};