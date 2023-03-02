#pragma once
#include "CoreExports.h"
#include <windows.h> 

CORE_API HINSTANCE CoreLoadLibrary(const char* libraryName);
CORE_API void UnloadLibrary(HINSTANCE handle);

