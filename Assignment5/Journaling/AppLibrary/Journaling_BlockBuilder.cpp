#include "Journaling_BlockBuilder.h"
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"


void Journaling_BlockBuilder_SetType(Application::BlockBuilder* blockBuilder, JournalBlockBuilderTypes type)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("SetType", blockBuilder);
		JournalIntInParam(type, "type");
	}

	blockBuilder->SetType(type);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}


JournalBlockBuilderTypes Journaling_BlockBuilder_GetType(Application::BlockBuilder* blockBuilder)
{
	//If Journaling write the thing things
	if (IsJournaling())
	{
		JournalStartCall("GetType", blockBuilder);
	}

	auto type  = blockBuilder->GetType();

	if (IsJournaling())
	{
		JournalReturnInt(type, "type");
		JournalEndCall();
	}

	return type;
}
