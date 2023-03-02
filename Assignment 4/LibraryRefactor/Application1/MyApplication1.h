#pragma once

#include "Application1Exports.h"
#include "../Utilities/LinkedList.h"


/// <summary>
/// This class does something entirely different thatn MyAppplication2
/// </summary>
class APPLICATION1_API MyApplication1
{
public:
	MyApplication1();
	virtual ~MyApplication1();

	void DoWork();

private:
	ArrayBasedLinkedList * m_arrayBasedLinkedList;

};

