#pragma once

#include "PartOpsUIExports.h"
#include <string>

namespace Application
{
	class PartFile;
}


PARTOPSUI_API Application::PartFile* OpenPartUI(std::string);

PARTOPSUI_API Application::PartFile* MakePartUI(std::string);

PARTOPSUI_API void SavePartUI(Application::PartFile* partFile);


