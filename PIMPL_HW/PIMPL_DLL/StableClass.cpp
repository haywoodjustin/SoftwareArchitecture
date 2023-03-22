// PIMPL_DLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "StableClass.h"
#include "SomeContainedClass1.h"
#include "SomeContainedClass2.h"


class StableImpl {
public: 

    StableImpl(); 

    BaseStableClass* GetBaseStableClass(); 
    SomeContainedClass1* GetSomeContainedClass1();
    SomeContainedClass2* GetSomeContainedClass2();

    BaseStableClass* m_BaseStableClass; 
    SomeContainedClass1* m_SomeContainedClass1;
    SomeContainedClass2* m_SomeContainedClass2; // Newly Added
};


StableClass::StableClass() {
    m_stableImpl = new StableImpl(); 
}

StableImpl::StableImpl(void)
{
    m_SomeContainedClass1 = new SomeContainedClass1(); 
    m_SomeContainedClass2 = new SomeContainedClass2();
}

//BaseStableClass functions

BaseStableClass* ::StableImpl::GetBaseStableClass()
{
    return m_BaseStableClass; 
}

BaseStableClass* ::StableClass::GetBaseStableClass()
{
    return m_stableImpl->GetBaseStableClass();
}

// SomeContainedClass1 functions

SomeContainedClass1*::StableImpl::GetSomeContainedClass1()
{
    return m_SomeContainedClass1;
}

SomeContainedClass1* StableClass::GetSomeContainedClass1() 
{
    return m_stableImpl->GetSomeContainedClass1(); 
}


//SomeContainedClass2 functions

SomeContainedClass2* StableImpl::GetSomeContainedClass2()
{
    return m_SomeContainedClass2;
}

SomeContainedClass2* StableClass::GetSomeContainedClass2()
{
    return m_stableImpl->GetSomeContainedClass2();
}
