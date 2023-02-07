#pragma once


#include <LinkedList.h>

/// <summary>
/// This class does something entirely different thatn MyAppplication1
/// </summary>
class MyApplication2
{
public:
	MyApplication2();
	virtual ~MyApplication2();

	void DoWork();

private:
	PointerBasedLinkedList* m_pointerBasedLinkedList;

};
