#pragma once
#include "AutomationBindingExports.h"
#include "AutomationAPI_IBuilder.h"

namespace AutomationAPI
{
	class CADObject;
	class BlockBuilder;
	class BlockBuilderImpl;
	/// <summary>
	/// BlockBuilder comment
	/// </summary>
	class AUTOMATIONBINDING_API BlockBuilder : public IBuilder
	{
		public:
			enum BlockBuilderTypes
			{
				TypesOriginAndEdgeLengths, /**Represents the block created by providing Originand Edge Lengths. */
				TypesTwoPointsAndHeight, /**Represents the block created by providing Two Pointsand Height.*/
				TypesDiagonalPoints /**Represents the block created by providing Diagonal Points. */
			};

			void SetType(BlockBuilderTypes type);
			BlockBuilderTypes GetType();

			void SetHeight(int h);
			int GetHeight();
			void SetWidth(int w);
			int GetWidth();
			void SetDepth(int d);
			int GetDepth();
			void SetOrigin(int x, int y, int z);
			void GetOrigin(int &x, int &y, int &z);


			CADObject* Commit() override;

			/*
			* Internal Usage only.
			*/
			static BlockBuilder* CreateBlockBuilder(int guid);
			virtual ~BlockBuilder();
			BlockBuilder() = delete;

		private:

			BlockBuilder(int guid);
			BlockBuilderImpl* m_blockBuilderImpl;

	};
}
