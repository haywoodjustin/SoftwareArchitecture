
#include "PIMPLDLL_EXPORTS.h"
#include "BaseStableClass.h"


class SomeContainedClass1;
class SomeContainedClass2;

// This class is exported from the dll
class PIMPLDLL_API StableClass : BaseStableClass {
public:
	StableClass(void);

	void Method1(int i) override; 
	void Method2(int i) override; // Newly Added

	SomeContainedClass1 * GetSomeContainedClass1();
	SomeContainedClass2 * GetSomeContainedClass2();

private:
	SomeContainedClass1* m_SomeContainedClass1;
	SomeContainedClass2* m_SomeContainedClass2; // Newly Added

};


