#pragma once
#include "FeatureOpsUIExports.h"
#include "..\AppLibrary\BlockBuilder.h"
namespace Application
{
	class PartFile;
	class Block;
	class BlockBuilder;
}



FEATUREOPSUI_API Application::BlockBuilder* CreateBlockBuilderUI(Application::PartFile* part, Application::Block *block);

FEATUREOPSUI_API void CreateBlockBuilderUI(Application::BlockBuilder* blockBuilder, JournalBlockBuilderTypes type);




