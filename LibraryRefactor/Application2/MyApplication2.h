#pragma once
#include "../Application2/Application2Exports.h"

#include "../BlobLibrary/LinkedList.h"

/// <summary>
/// This class does something entirely different thatn MyAppplication1
/// </summary>
class APPLICATION2_API MyApplication2
{
public:
	MyApplication2();
	virtual ~MyApplication2();

	void DoWork();

private:
	PointerBasedLinkedList* m_pointerBasedLinkedList;

};
