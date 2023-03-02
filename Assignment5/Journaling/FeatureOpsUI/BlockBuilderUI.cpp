#include "BlockBuilderUI.h"

#include <iostream>
#include "..\AppPartOps\PartOps.h"
#include "..\AppLibrary\Block.h"
#include "..\AppLibrary\BlockBuilder.h"
#include "..\AppLibrary\Journaling_FeatureCollection.h"
#include "..\AppLibrary\Journaling_BlockBuilder.h"

Application::BlockBuilder* CreateBlockBuilderUI(Application::PartFile* part, Application::Block *block)
{
	std::cout << "CreateBlockBuilderUI was called "<< std::endl;
	return Journaling_FeatureCollection_CreateBlockBuilder(part, block);

}

void CreateBlockBuilderUI(Application::BlockBuilder* blockBuilder, JournalBlockBuilderTypes type)
{
	std::cout << "CreateBlockBuilderUI was called " << std::endl;
	Journaling_BlockBuilder_SetType(blockBuilder, type);
}

