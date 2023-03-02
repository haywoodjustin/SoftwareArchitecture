#pragma once

#include "AppFeaturesOpsExports.h"
#include "..\AppLibrary\BlockBuilder.h"


APPLIBRARY_API void Journaling_BlockBuilder_SetType(Application::BlockBuilder* blockBuilder, JournalBlockBuilderTypes type);

APPLIBRARY_API JournalBlockBuilderTypes Journaling_BlockBuilder_GetType(Application::BlockBuilder* blockBuilder);
