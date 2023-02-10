#pragma once

#include "../ApplicationLibrary/AppExports.h"
#include "../BlobLibrary/LinkedList.h"


/// <summary>
/// This class does something entirely different thatn MyAppplication2
/// </summary>
class APPLICATIONLIBRARY_API MyApplication1
{
public:
	MyApplication1();
	virtual ~MyApplication1();

	void DoWork();

private:
	ArrayBasedLinkedList * m_arrayBasedLinkedList;

};

