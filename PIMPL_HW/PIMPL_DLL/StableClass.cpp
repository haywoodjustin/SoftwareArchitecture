// PIMPL_DLL.cpp : Defines the exported functions for the DLL.
//

#include "BaseStableClass.h"
#include "framework.h"
#include "StableClass.h"
#include "SomeContainedClass1.h"
#include "SomeContainedClass2.h"


class StableImpl : public BaseStableClass {
public: 

    void Method1(int i) override;
    void Method2(int i) override; // Newly Added

    SomeContainedClass1* GetSomeContainedClass1();
    SomeContainedClass2* GetSomeContainedClass2();

    SomeContainedClass1* m_SomeContainedClass1;
    SomeContainedClass2* m_SomeContainedClass2; // Newly Added
};

void StableImpl::Method1(int i)
{
}

void StableImpl::Method2(int i)
{
}

StableClass::StableClass() {
    m_stableImpl = new StableImpl(); 
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

