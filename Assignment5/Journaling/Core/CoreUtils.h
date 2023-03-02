#pragma once

#include "CoreExports.h"
#include <string>

CORE_API std::string BasePath();
CORE_API std::string RemoveLastDirectory(const std::string& dirPath);

