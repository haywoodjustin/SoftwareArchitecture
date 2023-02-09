// UserInterface.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "UserInterface.h"
#include "../BlobLibrary/MyApplication1.h"
#include "../BlobLibrary/MyApplication2.h"

UI::UI() : m_application1(nullptr), m_application2(nullptr)
{

}
void UI::Init()
{
	m_application1 = new MyApplication1();
	m_application2 = new MyApplication2();
}

void UI::StartGUILoop()
{
	m_application1->DoWork();

	m_application2->DoWork();


	delete m_application1;
	delete m_application2;

}
