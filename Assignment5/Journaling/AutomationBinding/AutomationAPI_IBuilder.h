#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class CADObject;
	/// <summary>
	/// IBuilder comment
	/// </summary>
	class AUTOMATIONBINDING_API IBuilder
	{
		/**
		* Commit the builder
		*/
		virtual CADObject * Commit() = 0;
	};
}
