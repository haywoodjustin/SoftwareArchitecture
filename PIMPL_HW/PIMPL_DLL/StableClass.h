
#include "PIMPLDLL_EXPORTS.h"

class SomeContainedClass1;
class SomeContainedClass2;
class StableImpl; 

class PIMPLDLL_API StableClass {
public:

	SomeContainedClass1* GetSomeContainedClass1();
	SomeContainedClass2* GetSomeContainedClass2();

private:
	StableClass(void);
	StableImpl* m_stableImpl; 
};


