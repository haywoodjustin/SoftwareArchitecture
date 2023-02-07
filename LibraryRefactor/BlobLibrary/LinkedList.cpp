
#include "LinkedList.h"
#include <iostream>
#include "BI.h"
using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{
	//hello
}
Node::Node(int val, Node* nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node* Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	//TODO - hint, you can recursively handle this
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}
/** Returns true  if list is empty, otherwise true */
bool PointerBasedLinkedList::isEmpty() const
{
	return false;
	//TODO
}
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	return false;
	//TODO
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	//TODO
	return false;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	m_head = NULL;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{

}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";

	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{

}

bool ArrayBasedLinkedList::isEmpty() const
{
	return true;
	//TODO
}
bool ArrayBasedLinkedList::add(int val)
{
	//TODO
	return false;
}
bool ArrayBasedLinkedList::remove(int val)
{
	//TODO
	return false;
}
void ArrayBasedLinkedList::clear()
{
	GetBusinessIntelligence()->LogSomething("Something");
	// TODO
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";

	//TODO

	return str;
}
