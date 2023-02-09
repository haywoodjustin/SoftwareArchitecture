#pragma once

#include "UserInterfaceExports.h"

// This class is exported from the dll
class USERINTERFACE_API CUserInterface {
public:
	CUserInterface(void);
	// TODO: add your methods here.
};

extern USERINTERFACE_API int nUserInterface;

USERINTERFACE_API int fnUserInterface(void);