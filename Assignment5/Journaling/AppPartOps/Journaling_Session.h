#pragma once
#include "AppPartOpsExports.h"
#include <string>
#include "PartOps.h"

extern APPPARTOPS_API Application::PartFile* Journaling_Session_MakePart(std::string);

extern APPPARTOPS_API Application::PartFile* Journaling_Session_OpenPart(std::string);

