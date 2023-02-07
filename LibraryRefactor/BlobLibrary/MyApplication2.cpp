#include "MyApplication2.h"

#include <BI.h>
#include <MyApplication2.h>


MyApplication2::MyApplication2() : m_pointerBasedLinkedList(nullptr)
{
}
MyApplication2::~MyApplication2()
{
	m_pointerBasedLinkedList->clear();
	delete m_pointerBasedLinkedList;
}

void MyApplication2::DoWork()
{
	GetBusinessIntelligence()->LogSomething("MyApp2");

	m_pointerBasedLinkedList = new PointerBasedLinkedList;

	m_pointerBasedLinkedList->add(22);

}
