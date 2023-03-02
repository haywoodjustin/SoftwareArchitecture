#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class BlockBuilder;
	class Block;
	/// <summary>
	/// FeatureCollection comment
	/// </summary>
	class AUTOMATIONBINDING_API FeatureCollection
	{
		public:
			FeatureCollection(int guid);

			virtual ~FeatureCollection();

			/// <summary>
			/// Create a Block builder.
			/// </summary>
			/// <param name="block"> if nullptr is passed in this will be created in 
			/// create mode, otherwise it be in edit mode.</param>
			/// <returns></returns>
			BlockBuilder* CreateBlockBuilder(Block* block);


		private:
			int m_guid;
	};
}
