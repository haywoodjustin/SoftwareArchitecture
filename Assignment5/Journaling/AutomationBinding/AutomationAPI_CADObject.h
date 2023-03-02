#pragma once
#include "AutomationBindingExports.h"
#include "AutomationAPI_ICADObject.h"

namespace AutomationAPI
{
	/// <summary>
	/// CADObject comment
	/// </summary>
	class AUTOMATIONBINDING_API CADObject : public ICADObject
	{
		public:
			int GetGuid() override;

	};
}
