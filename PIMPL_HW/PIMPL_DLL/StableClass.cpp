// PIMPL_DLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "StableClass.h"
#include "SomeContainedClass1.h"
#include "SomeContainedClass2.h"



StableClass::StableClass(void) : m_SomeContainedClass1(nullptr), m_SomeContainedClass2(nullptr)
{

}

void StableClass::Method1(int i)
{

}

void StableClass::Method2(int i)
{

}

SomeContainedClass1* StableClass::GetSomeContainedClass1()
{
    return m_SomeContainedClass1;
}

SomeContainedClass2* StableClass::GetSomeContainedClass2()
{
    return m_SomeContainedClass2;
}
