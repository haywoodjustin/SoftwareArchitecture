#pragma once
#include "AppFeaturesOpsExports.h"
#include "..\Core\GuidObject.h"

// TODO these probably shoudl be in their own file, 
// but deferring this to when get a generator to handle this for us
enum JournalBlockBuilderTypes
{
	JournalTypesOriginAndEdgeLengths, /**Represents the block created by providing Originand Edge Lengths. */
	JournalTypesTwoPointsAndHeight, /**Represents the block created by providing Two Pointsand Height.*/
	JournalTypesDiagonalPoints /**Represents the block created by providing Diagonal Points. */
};

namespace Application
{
	class Block;

	class APPLIBRARY_API BlockBuilder : public GuidObject
	{
		public:
			BlockBuilder() = delete;
			BlockBuilder(Application::Block* block, int guid);
			JournalBlockBuilderTypes GetType();
			void SetType(JournalBlockBuilderTypes type);

		private:
			Block* m_block;
			JournalBlockBuilderTypes m_journalBlockBuilderTypes;

	};
}


