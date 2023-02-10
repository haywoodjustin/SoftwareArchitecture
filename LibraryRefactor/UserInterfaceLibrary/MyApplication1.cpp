#include "MyApplication1.h"

#include "../BlobLibrary/BI.h"

MyApplication1::MyApplication1() : m_arrayBasedLinkedList(nullptr)
{
}
MyApplication1::~MyApplication1()
{
	m_arrayBasedLinkedList->clear();
	delete m_arrayBasedLinkedList;
}

void MyApplication1::DoWork()
{
	GetBusinessIntelligence()->LogSomething("MyApp1");

	m_arrayBasedLinkedList = new ArrayBasedLinkedList;


	m_arrayBasedLinkedList->add(11);
	

}
