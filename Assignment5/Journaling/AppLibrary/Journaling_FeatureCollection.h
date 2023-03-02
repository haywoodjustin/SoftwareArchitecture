#pragma once
#include "AppFeaturesOpsExports.h"

namespace Application
{
	class Block;
	class PartFile;
	class BlockBuilder;
}


APPLIBRARY_API Application::BlockBuilder* Journaling_FeatureCollection_CreateBlockBuilder(Application::PartFile *part, Application::Block* block);

