#pragma once


#include <LinkedList.h>


/// <summary>
/// This class does something entirely different thatn MyAppplication2
/// </summary>
class MyApplication1
{
public:
	MyApplication1();
	virtual ~MyApplication1();

	void DoWork();

private:
	ArrayBasedLinkedList * m_arrayBasedLinkedList;

};

