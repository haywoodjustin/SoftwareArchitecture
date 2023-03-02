#pragma once
#include "AppFeaturesOpsExports.h"
#include "Feature.h"

#include <iostream>
#include <fstream>
#include "..\Core\GuidObject.h"

void ProcessBlock(std::ifstream& streamObject);

namespace Application
{
	class APPLIBRARY_API IBlock : public GuidObject
	{
	public:
		virtual std::string GetVersion() = 0;
		IBlock(int guid) : GuidObject(guid)
		{

		}
		IBlock() = delete;
	};


	class APPLIBRARY_API Block : public Application::Feature, public IBlock
	{
		public:
			Block() = delete;
			Block(int guid) : IBlock(guid)
			{

			}
			std::string GetVersion() override
			{
				return "1";
			}
	};
}

