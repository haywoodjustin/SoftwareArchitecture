
#include "PIMPLDLL_EXPORTS.h"

class SomeContainedClass1;
class SomeContainedClass2;
class BaseStableClass; 
class StableImpl; 

class PIMPLDLL_API StableClass {
public:
	StableClass(void);

	BaseStableClass* GetBaseStableClass();
	SomeContainedClass1* GetSomeContainedClass1();
	SomeContainedClass2* GetSomeContainedClass2();

private:
	StableImpl* m_stableImpl; 
};


